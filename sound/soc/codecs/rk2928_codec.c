/*
 * rk2928_codec.c ALSA SoC RK2928 codec driver
 *
 * Copyright 2012 Rockchip
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/gpio.h>
#include <linux/platform_device.h>
#include <linux/slab.h>

#include <asm/io.h>
#include <asm/delay.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>
#include <mach/cru.h>
#include <mach/iomux.h>
#include <mach/cpu.h>
#include <linux/clk.h>
#include "rk2928_codec.h"

#define HP_OUT 0
#define HP_IN  1

static struct rk2928_codec_data {
	struct device	*dev;
	int 			regbase;
	int				regbase_phy;
	int				regsize_phy;
	struct clk		*pclk;
	int				mute;
	int				hdmi_enable;
	int				spkctl;
} rk2928_data;

static const struct snd_soc_dapm_widget rk2928_dapm_widgets[] = {
	SND_SOC_DAPM_DAC("DACL", "HIFI Playback", CODEC_REG_POWER, 5, 1),
	SND_SOC_DAPM_DAC("DACR", "HIFI Playback", CODEC_REG_POWER, 4, 1),
	SND_SOC_DAPM_PGA("DACL Amp", CODEC_REG_DAC_GAIN, 2, 0, NULL, 0),
	SND_SOC_DAPM_PGA("DACR Amp", CODEC_REG_DAC_GAIN, 0, 0, NULL, 0),
	SND_SOC_DAPM_OUTPUT("SPKL"),
	SND_SOC_DAPM_OUTPUT("SPKR"),
	SND_SOC_DAPM_ADC("ADCL", "HIFI Capture", CODEC_REG_POWER, 3, 1),
	SND_SOC_DAPM_INPUT("MICL"),
	SND_SOC_DAPM_ADC("ADCR", "HIFI Capture", CODEC_REG_POWER, 2, 1),
	SND_SOC_DAPM_INPUT("MICR"),
};

static const struct snd_soc_dapm_route rk2928_audio_map[] = {
	{"SPKL", "DACL Amp", "DACL"},
	{"SPKR", "DACR Amp", "DACR"},
	{"ADCL", NULL, "MICL"},
	{"ADCR", NULL, "MICR"},
};

static const struct snd_soc_dapm_widget rk2926_dapm_widgets[] = {
	SND_SOC_DAPM_DAC("DACL", "HIFI Playback", CODEC_REG_POWER, 5, 1),
	SND_SOC_DAPM_DAC("DACR", "HIFI Playback", CODEC_REG_POWER, 4, 1),
	SND_SOC_DAPM_PGA("DACL Amp", CODEC_REG_DAC_GAIN, 2, 0, NULL, 0),
	SND_SOC_DAPM_PGA("DACR Amp", CODEC_REG_DAC_GAIN, 0, 0, NULL, 0),
	SND_SOC_DAPM_OUTPUT("SPKL"),
	SND_SOC_DAPM_OUTPUT("SPKR"),
	SND_SOC_DAPM_ADC("ADCR", "HIFI Capture", CODEC_REG_POWER, 2, 1),
	SND_SOC_DAPM_INPUT("MICR"),
};

static const struct snd_soc_dapm_route rk2926_audio_map[] = {
	{"SPKL", "DACL Amp", "DACL"},
	{"SPKR", "DACR Amp", "DACR"},
	{"ADCR", NULL, "MICR"},
};



static unsigned int rk2928_read(struct snd_soc_codec *codec, unsigned int reg)
{	
	return readl(rk2928_data.regbase + reg*4);
}

static int rk2928_write(struct snd_soc_codec *codec, unsigned int reg, unsigned int value)
{
	DBG("%s reg 0x%02x value 0x%02x", __FUNCTION__, reg, value);
	writel(value, rk2928_data.regbase + reg*4);
//	if( (reg == CODEC_REG_POWER) && ( (value & m_PD_DAC) == 0)) {
//		msleep(100);
//	}
	return 0;
}

static int rk2928_write_mask(struct snd_soc_codec *codec, unsigned int reg, 
					unsigned int mask, unsigned int value)
{
	unsigned int regvalue = rk2928_read(codec, reg);
	
	DBG("%s reg 0x%02x mask 0x%02x value 0x%02x", __FUNCTION__, reg, mask, value);
	
	regvalue &= ~mask;
	regvalue |= mask & value;
	return rk2928_write(codec, reg, regvalue);
}
int   hardware_mute_pin_can_action;   //lizhengwei add

void codec_set_spk(bool on)
{
	if(on == 0) {
		DBG("%s speaker is disabled\n", __FUNCTION__);
		rk2928_data.hdmi_enable = 1;
		if(rk2928_data.mute == 0) {
			rk2928_write(NULL, CODEC_REG_DAC_MUTE, v_MUTE_DAC(1));
			if(rk2928_data.spkctl != INVALID_GPIO) {
				gpio_direction_output(rk2928_data.spkctl, GPIO_LOW);
			}
		}
	}
	else {
		DBG("%s speaker is enabled\n", __FUNCTION__);
		rk2928_data.hdmi_enable = 0;
		if(rk2928_data.mute == 0) {
			rk2928_write(NULL, CODEC_REG_DAC_MUTE, v_MUTE_DAC(0));
			if(rk2928_data.spkctl != INVALID_GPIO) {
				gpio_direction_output(rk2928_data.spkctl, GPIO_HIGH);
			}
		}
	}
}

static int rk2928_audio_hw_params(struct snd_pcm_substream *substream,
				    struct snd_pcm_hw_params *params,
				    struct snd_soc_dai *dai)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_codec *codec = rtd->codec;
	struct rk2928_codec_data *priv = snd_soc_codec_get_drvdata(codec);
	
	DBG("%s", __FUNCTION__);
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		rk2928_write_mask(codec, CODEC_REG_POWER, m_PD_MIC_BIAS | m_PD_CODEC | m_PD_DAC, 
			v_PD_MIC_BIAS(0) | v_PD_CODEC(0) | v_PD_DAC(0));
		msleep(50);
		if(!rk2928_data.hdmi_enable) {
			if(rk2928_data.spkctl != INVALID_GPIO) {
				gpio_direction_output(rk2928_data.spkctl, GPIO_HIGH);
			}
		}
	}
	
	return 0;
}

static int rk2928_audio_trigger(struct snd_pcm_substream *substream, int cmd,
				struct snd_soc_dai *dai)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_codec *codec = rtd->codec;
	struct rk2928_codec_data *priv = snd_soc_codec_get_drvdata(codec);
	int err = 0;
	int data, pd_adc;
	DBG("%s cmd 0x%x", __FUNCTION__, cmd);
	
	switch (cmd) {
		case SNDRV_PCM_TRIGGER_START:
		case SNDRV_PCM_TRIGGER_RESUME:
		case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
			if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
//				rk2928_write(codec, CODEC_REG_DAC_GAIN, v_GAIN_DAC(DAC_GAIN_3DB_P));
				data = rk2928_read(codec, CODEC_REG_POWER);
				if(soc_is_rk2928g()){
					if( (data & m_PD_ADC) == 0) {
						data &= ~m_PD_ADC;
						data |= v_PD_ADC(1);
						pd_adc = 1;
					}
					else
						pd_adc = 0;
				}
				else{
					if( (data & m_PD_ADC_R) == 0) {
						data &= ~m_PD_ADC_R;
						data |= v_PD_ADC_R(1);
						pd_adc = 1;
					}
					else
						pd_adc = 0;
				}
				if(pd_adc == 1) {
					DBG("%s reg 0x%02x value 0x%02x", __FUNCTION__, CODEC_REG_POWER, data);
					writel(data, rk2928_data.regbase + CODEC_REG_POWER*4);
					udelay(100);						
				}
				rk2928_write(codec, CODEC_REG_ADC_SOURCE, 0x03);
				udelay(100);
				rk2928_write(codec, CODEC_REG_ADC_SOURCE, 0x00);
				
				if(pd_adc == 1) {
					udelay(100);
					data = rk2928_read(codec, CODEC_REG_POWER);
					if( soc_is_rk2928g() ) {
						data &= ~m_PD_ADC;
						data |= v_PD_ADC(0);
					}
					else {
						data &= ~m_PD_ADC_R;
						data |= v_PD_ADC_R(0);
					}
					DBG("%s reg 0x%02x value 0x%02x", __FUNCTION__, CODEC_REG_POWER, data);
					writel(data, rk2928_data.regbase + CODEC_REG_POWER*4);
				}
				if(!rk2928_data.hdmi_enable) {
					rk2928_write(codec, CODEC_REG_DAC_MUTE, v_MUTE_DAC(0));
//<<<<<<< HEAD
//					if(rk2928_data.spkctl != INVALID_GPIO) {
					      hardware_mute_pin_can_action =1;   //lizhengwei add
//						gpio_direction_output(rk2928_data.spkctl, GPIO_HIGH);
//					}
//=======
					if(rk2928_data.spkctl != INVALID_GPIO) {
						gpio_direction_output(rk2928_data.spkctl, GPIO_HIGH);
					}
//>>>>>>> 00f488d0750ddf48d965ee9b64578c95e6f4f7f7
				}
				rk2928_data.mute = 0;
			}
			else {
				/*lizhengwei add start*/
				if(soc_is_rk2928g()){	//ÎªÁËÂ¼ÒôÐ§¹û¶øµ÷Õû
			
				rk2928_write(codec, CODEC_REG_ADC_PGA_GAIN, 0xAA);//	rk2928_write(codec, CODEC_REG_ADC_PGA_GAIN, 0xFF);
				rk2928_write(codec, 0x08, 0xff);
				rk2928_write(codec, 0x09, 0x07);
				}
				else{			
			       rk2928_write(codec, CODEC_REG_ADC_PGA_GAIN, 0x0a);//    rk2928_write(codec, CODEC_REG_ADC_PGA_GAIN, 0x0f);
				rk2928_write(codec, 0x08, 0xff);
				rk2928_write(codec, 0x09, 0x08);
				}
				/*lizhengwei add end*/	
			}
			break;
		case SNDRV_PCM_TRIGGER_STOP:
		case SNDRV_PCM_TRIGGER_SUSPEND:
		case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
			if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
				if(rk2928_data.spkctl != INVALID_GPIO) {
					gpio_direction_output(rk2928_data.spkctl, GPIO_LOW);
					mdelay(1);
				}
				rk2928_write(codec, CODEC_REG_DAC_MUTE, v_MUTE_DAC(1));
				rk2928_data.mute = 1;
			}
			break;
		default:
			err = -EINVAL;
	}
	return err;
}

static int rk2928_audio_startup(struct snd_pcm_substream *substream,
				  struct snd_soc_dai *dai)
{
//	struct snd_soc_pcm_runtime *rtd = substream->private_data;
//	struct snd_soc_codec *codec = rtd->codec;
	DBG("%s", __FUNCTION__);
	return 0;
}

static int rk2928_set_bias_level(struct snd_soc_codec *codec,
			      enum snd_soc_bias_level level)
{
	DBG("%s level %d", __FUNCTION__, level);
	
//        msleep(100);

	if(codec == NULL)
		return -1;
		
	switch(level)
	{
		case SND_SOC_BIAS_ON:
			break;
		case SND_SOC_BIAS_PREPARE:
			rk2928_write_mask(codec, CODEC_REG_POWER, m_PD_MIC_BIAS | m_PD_CODEC, v_PD_MIC_BIAS(0) | v_PD_CODEC(0));
			break;
		case SND_SOC_BIAS_STANDBY:
		case SND_SOC_BIAS_OFF:
			rk2928_write(codec, CODEC_REG_POWER, v_PWR_OFF);
			break;
		default:
			return -1;
	}
	codec->dapm.bias_level = level;
	return 0;
}

/*static void rk2929_codec_reset(void)
{
	// Reset Codec
	cru_set_soft_reset(SOFT_RST_ACODEC, true);
	udelay(1000);
	cru_set_soft_reset(SOFT_RST_ACODEC, false);
}*/

#define v_PWR_ON				(0 << 1)
static struct delayed_work delaywork;
struct snd_soc_codec *snd_reset;

#include "rk2928_speaker.c"
static void  codec_reset(struct work_struct *work)
{
  	int liTmp;
	for(liTmp = 0 ; liTmp < 2; liTmp++)
	{
		rk2928_write(snd_reset, CODEC_REG_POWER, v_PWR_OFF);
		msleep(3000); 
		rk2928_write(snd_reset, CODEC_REG_POWER, v_PWR_ON);
	}
}

static int rk2928_probe(struct snd_soc_codec *codec)
{
	struct platform_device *pdev = to_platform_device(codec->dev);
	struct snd_soc_dapm_context *dapm = &codec->dapm;
	struct resource *res, *mem;
	int ret;
	
	DBG("%s", __FUNCTION__);
	
	snd_reset = codec;
	snd_soc_codec_set_drvdata(codec, &rk2928_data);
	
	rk2928_data.dev = &pdev->dev;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "Unable to get register resource\n");
		ret = -ENXIO;
		goto err0;
	}
	rk2928_data.regbase_phy = res->start;
	rk2928_data.regsize_phy = (res->end - res->start) + 1;
	mem = request_mem_region(res->start, (res->end - res->start) + 1, pdev->name);
	if (!mem)
	{
    	dev_err(&pdev->dev, "failed to request mem region for rk2928 codec\n");
    	ret = -ENOENT;
    	goto err0;
	}

	
	rk2928_data.regbase = (int)ioremap(res->start, (res->end - res->start) + 1);
	if (!rk2928_data.regbase) {
		dev_err(&pdev->dev, "cannot ioremap acodec registers\n");
		ret = -ENXIO;
		goto err1;
	}
	
	rk2928_data.pclk = clk_get(NULL,"pclk_acodec");
	if(IS_ERR(rk2928_data.pclk))
	{
		dev_err(rk2928_data.dev, "Unable to get acodec hclk\n");
		ret = -ENXIO;
		goto err1;
	}
	clk_enable(rk2928_data.pclk);

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if(!res) {
		rk2928_data.spkctl = INVALID_GPIO;
	}
	else {
		rk2928_data.spkctl = res->start;
	}
	
	if(rk2928_data.spkctl != INVALID_GPIO) {
		ret = gpio_request(rk2928_data.spkctl, NULL);
		if (ret != 0) {
			gpio_free(rk2928_data.spkctl);
		}
		else
			gpio_direction_output(rk2928_data.spkctl, GPIO_LOW);
	}

	create_speaker_class(&speaker_dev);
	//rk2929_codec_reset();

	// Select SDI input from internal audio codec
	writel(0x04000400, RK2928_GRF_BASE + GRF_SOC_CON0);
	
	// Mute and Power off codec
	rk2928_write(codec, CODEC_REG_DAC_MUTE, v_MUTE_DAC(1));
	
	//Reset Codec
	INIT_DELAYED_WORK(&delaywork, codec_reset);
	schedule_delayed_work(&delaywork, msecs_to_jiffies(10000));
	
	rk2928_set_bias_level(codec, SND_SOC_BIAS_OFF);
	if(soc_is_rk2928g()){	
	    snd_soc_dapm_new_controls(dapm, rk2928_dapm_widgets,
		ARRAY_SIZE(rk2928_dapm_widgets));
	    snd_soc_dapm_add_routes(dapm, rk2928_audio_map, ARRAY_SIZE(rk2928_audio_map));
	}else{
	    snd_soc_dapm_new_controls(dapm, rk2926_dapm_widgets,
		ARRAY_SIZE(rk2926_dapm_widgets));
	    snd_soc_dapm_add_routes(dapm, rk2926_audio_map, ARRAY_SIZE(rk2926_audio_map));
	}

	return 0;
	
err1:
	release_mem_region(res->start,(res->end - res->start) + 1);
//	clk_disable(rk2928_data.hclk);
err0:
	DBG("%s failed", __FUNCTION__);
	return ret;
}

static int rk2928_remove(struct snd_soc_codec *codec)
{
/* PJF@20121218: once edit */
    destroy_speaker_class(&speaker_dev);
/* PJF@20121218: edit end */
	return 0;
}

static int rk2928_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
	DBG("%s", __FUNCTION__);
	rk2928_set_bias_level(codec, SND_SOC_BIAS_OFF);
	clk_disable(rk2928_data.pclk);
	return 0;
}

static int rk2928_resume(struct snd_soc_codec *codec)
{
	DBG("%s", __FUNCTION__);
	clk_enable(rk2928_data.pclk);
	rk2928_write(codec, CODEC_REG_POWER, v_PD_ADC(1) | v_PD_DAC(1) | v_PD_MIC_BIAS(1));
	return 0;
}

static struct snd_soc_codec_driver rk2928_audio_codec_drv = {
	.probe = rk2928_probe,
	.remove = rk2928_remove,
	.suspend = rk2928_suspend,
	.resume = rk2928_resume,
	.read = rk2928_read,
	.write = rk2928_write,
	.set_bias_level = rk2928_set_bias_level,
};

static struct snd_soc_dai_ops rk2928_audio_codec_ops = {
	.hw_params = rk2928_audio_hw_params,
	.trigger = rk2928_audio_trigger,
	.startup = rk2928_audio_startup,
};

static struct snd_soc_dai_driver rk2928_codec_dai = {
	.name = "rk2928-codec",
	.playback = {
		.stream_name = "HIFI Playback",
		.channels_min = 1,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_8000_48000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S20_3LE | 
			SNDRV_PCM_FMTBIT_S24_LE,
	},
	.capture = {
		.stream_name = "HIFI Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_8000_48000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S18_3LE,
	},
	.ops = &rk2928_audio_codec_ops,
};

static __devinit int rk2928_codec_probe(struct platform_device *pdev)
{
	int r;
	
	DBG("%s", __FUNCTION__);
	
	/* Register ASoC codec DAI */
	r = snd_soc_register_codec(&pdev->dev, &rk2928_audio_codec_drv,
					&rk2928_codec_dai, 1);
	if (r) {
		dev_err(&pdev->dev, "can't register ASoC rk2928 audio codec\n");
		return r;
	}
	
	DBG("%s success", __FUNCTION__);
	return 0;
	
}

static int __devexit rk2928_codec_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

static struct platform_driver rk2928_codec_driver = {
	.probe          = rk2928_codec_probe,
	.remove         = __devexit_p(rk2928_codec_remove),
	.driver         = {
		.name   = "rk2928-codec",
		.owner  = THIS_MODULE,
	},
};

static int __init rk2928_codec_init(void)
{
	return platform_driver_register(&rk2928_codec_driver);
}
module_init(rk2928_codec_init);

static void __exit rk2928_codec_exit(void)
{
	#ifdef CODEC_I2C_MODE
	i2c_del_driver(&rk2928_codec_driver);
	#else
	platform_driver_unregister(&rk2928_codec_driver);
	#endif
}
module_exit(rk2928_codec_exit);

MODULE_DESCRIPTION("ASoC RK2928 codec driver");
MODULE_LICENSE("GPL");

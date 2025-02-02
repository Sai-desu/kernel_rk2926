//#define CONFIG_CAMERA_PMU_GPIO_RESEVRT
//#define CONFIG_CAMERA_BACK_USE_GC2035_REPLACE_SP0838
#define CONFIG_CAMERA_BACK_USE_GC0329_REPLACE_SP2518
#ifdef CONFIG_VIDEO_RK29
/*---------------- Camera Sensor Macro Define Begin  ------------------------*/
/*---------------- Camera Sensor Configuration Macro Begin ------------------------*/
#ifdef  CONFIG_CAMERA_BACK_USE_GC0329_REPLACE_SP2518
#define CONFIG_SENSOR_0 RK29_CAM_SENSOR_GC0329	    /* back camera sensor */
#define CONFIG_SENSOR_IIC_ADDR_0		0x62
#else
#define CONFIG_SENSOR_0 RK29_CAM_SENSOR_SP2518 			/* back camera sensor */
#define CONFIG_SENSOR_IIC_ADDR_0		0x60
#endif
#define CONFIG_SENSOR_IIC_ADAPTER_ID_0	  1
#define CONFIG_SENSOR_CIF_INDEX_0                    0
#define CONFIG_SENSOR_ORIENTATION_0 	  90
#define CONFIG_SENSOR_POWER_PIN_0		  INVALID_GPIO
#define CONFIG_SENSOR_RESET_PIN_0		  INVALID_GPIO
#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
#if defined(CONFIG_MACH_RK2928_SDK)
#define CONFIG_SENSOR_POWERDN_PIN_0       RK2928_PIN3_PD7
#else
#define CONFIG_SENSOR_POWERDN_PIN_0 	  RK2928_PIN3_PB3
#endif
#else
#define CONFIG_SENSOR_POWERDN_PIN_0 	        INVALID_GPIO//RK2928_PIN3_PB3
#endif
#define CONFIG_SENSOR_FALSH_PIN_0		  INVALID_GPIO
#define CONFIG_SENSOR_POWERACTIVE_LEVEL_0 RK29_CAM_POWERACTIVE_L
#define CONFIG_SENSOR_RESETACTIVE_LEVEL_0 RK29_CAM_RESETACTIVE_L
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_0 RK29_CAM_POWERDNACTIVE_H
#define CONFIG_SENSOR_FLASHACTIVE_LEVEL_0 RK29_CAM_FLASHACTIVE_L

#define CONFIG_SENSOR_QCIF_FPS_FIXED_0		15000
#define CONFIG_SENSOR_240X160_FPS_FIXED_0   15000
#define CONFIG_SENSOR_QVGA_FPS_FIXED_0		15000
#define CONFIG_SENSOR_CIF_FPS_FIXED_0		15000
#define CONFIG_SENSOR_VGA_FPS_FIXED_0		15000
#define CONFIG_SENSOR_480P_FPS_FIXED_0		15000
#define CONFIG_SENSOR_SVGA_FPS_FIXED_0		15000
#define CONFIG_SENSOR_720P_FPS_FIXED_0		30000

#ifdef  CONFIG_CAMERA_BACK_USE_GC2035_REPLACE_SP0838
#define CONFIG_SENSOR_01 RK29_CAM_SENSOR_GC2035       /* back camera sensor 1 */
#define CONFIG_SENSOR_IIC_ADDR_01 	    0x78
#else
#define CONFIG_SENSOR_01 RK29_CAM_SENSOR_SP0838        /* back camera sensor 1 */
#define CONFIG_SENSOR_IIC_ADDR_01 	    0x30
#endif
#define CONFIG_SENSOR_CIF_INDEX_01                    0
#define CONFIG_SENSOR_IIC_ADAPTER_ID_01    1
#define CONFIG_SENSOR_ORIENTATION_01       90
#define CONFIG_SENSOR_POWER_PIN_01         INVALID_GPIO
#define CONFIG_SENSOR_RESET_PIN_01         INVALID_GPIO
#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
#if defined(CONFIG_MACH_RK2928_SDK)
#define CONFIG_SENSOR_POWERDN_PIN_01       RK2928_PIN3_PD7
#else
#define CONFIG_SENSOR_POWERDN_PIN_01 	  RK2928_PIN3_PB3
#endif
#else
#define CONFIG_SENSOR_POWERDN_PIN_01       INVALID_GPIO//RK2928_PIN3_PB3
#endif
#define CONFIG_SENSOR_FALSH_PIN_01         INVALID_GPIO
#define CONFIG_SENSOR_POWERACTIVE_LEVEL_01 RK29_CAM_POWERACTIVE_L
#define CONFIG_SENSOR_RESETACTIVE_LEVEL_01 RK29_CAM_RESETACTIVE_L
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_01 RK29_CAM_POWERDNACTIVE_H
#define CONFIG_SENSOR_FLASHACTIVE_LEVEL_01 RK29_CAM_FLASHACTIVE_L

#define CONFIG_SENSOR_QCIF_FPS_FIXED_01      15000
#define CONFIG_SENSOR_240X160_FPS_FIXED_01   15000
#define CONFIG_SENSOR_QVGA_FPS_FIXED_01      15000
#define CONFIG_SENSOR_CIF_FPS_FIXED_01       15000
#define CONFIG_SENSOR_VGA_FPS_FIXED_01       15000
#define CONFIG_SENSOR_480P_FPS_FIXED_01      15000
#define CONFIG_SENSOR_SVGA_FPS_FIXED_01      15000
#define CONFIG_SENSOR_720P_FPS_FIXED_01     30000

#define CONFIG_SENSOR_02 RK29_CAM_SENSOR_GC0308	 /* back camera sensor 2 */
#define CONFIG_SENSOR_IIC_ADDR_02 	    0x42
#define CONFIG_SENSOR_CIF_INDEX_02                    0
#define CONFIG_SENSOR_IIC_ADAPTER_ID_02    1
#define CONFIG_SENSOR_ORIENTATION_02       90
#define CONFIG_SENSOR_POWER_PIN_02         INVALID_GPIO
#define CONFIG_SENSOR_RESET_PIN_02         INVALID_GPIO
#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
#if defined(CONFIG_MACH_RK2928_SDK)
#define CONFIG_SENSOR_POWERDN_PIN_02       RK2928_PIN3_PD7
#else
#define CONFIG_SENSOR_POWERDN_PIN_02 	  RK2928_PIN3_PB3
#endif
#else
#define CONFIG_SENSOR_POWERDN_PIN_02       INVALID_GPIO//RK2928_PIN3_PB3
#endif
#define CONFIG_SENSOR_FALSH_PIN_02         INVALID_GPIO
#define CONFIG_SENSOR_POWERACTIVE_LEVEL_02 RK29_CAM_POWERACTIVE_L
#define CONFIG_SENSOR_RESETACTIVE_LEVEL_02 RK29_CAM_RESETACTIVE_L
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_02 RK29_CAM_POWERDNACTIVE_H
#define CONFIG_SENSOR_FLASHACTIVE_LEVEL_02 RK29_CAM_FLASHACTIVE_L

#define CONFIG_SENSOR_QCIF_FPS_FIXED_02      15000
#define CONFIG_SENSOR_240X160_FPS_FIXED_02   15000
#define CONFIG_SENSOR_QVGA_FPS_FIXED_02      15000
#define CONFIG_SENSOR_CIF_FPS_FIXED_02       15000
#define CONFIG_SENSOR_VGA_FPS_FIXED_02       15000
#define CONFIG_SENSOR_480P_FPS_FIXED_02      15000
#define CONFIG_SENSOR_SVGA_FPS_FIXED_02      15000
#define CONFIG_SENSOR_720P_FPS_FIXED_02      30000

#define CONFIG_SENSOR_1 RK29_CAM_SENSOR_SP0838                      /* front camera sensor 0 */
#define CONFIG_SENSOR_IIC_ADDR_1 	   0x30
#define CONFIG_SENSOR_IIC_ADAPTER_ID_1	  1
#define CONFIG_SENSOR_CIF_INDEX_1				  0
#define CONFIG_SENSOR_ORIENTATION_1       270
#define CONFIG_SENSOR_POWER_PIN_1         INVALID_GPIO
#define CONFIG_SENSOR_RESET_PIN_1         INVALID_GPIO
#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
#define CONFIG_SENSOR_POWERDN_PIN_1       INVALID_GPIO//RK2928_PIN3_PB3
#else
#if defined(CONFIG_MACH_RK2928_SDK)
#define CONFIG_SENSOR_POWERDN_PIN_1       RK2928_PIN3_PD7
#else
#define CONFIG_SENSOR_POWERDN_PIN_1 	  RK2928_PIN3_PB3
#endif
#endif
#define CONFIG_SENSOR_FALSH_PIN_1         INVALID_GPIO
#define CONFIG_SENSOR_POWERACTIVE_LEVEL_1 RK29_CAM_POWERACTIVE_L
#define CONFIG_SENSOR_RESETACTIVE_LEVEL_1 RK29_CAM_RESETACTIVE_L
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_1 RK29_CAM_POWERDNACTIVE_H
#define CONFIG_SENSOR_FLASHACTIVE_LEVEL_1 RK29_CAM_FLASHACTIVE_L

#define CONFIG_SENSOR_QCIF_FPS_FIXED_1		15000
#define CONFIG_SENSOR_240X160_FPS_FIXED_1   15000
#define CONFIG_SENSOR_QVGA_FPS_FIXED_1		15000
#define CONFIG_SENSOR_CIF_FPS_FIXED_1		15000
#define CONFIG_SENSOR_VGA_FPS_FIXED_1		15000
#define CONFIG_SENSOR_480P_FPS_FIXED_1		15000
#define CONFIG_SENSOR_SVGA_FPS_FIXED_1		15000
#define CONFIG_SENSOR_720P_FPS_FIXED_1		30000

#define CONFIG_SENSOR_11 RK29_CAM_SENSOR_GC0329     /* front camera sensor 1 */
#define CONFIG_SENSOR_IIC_ADDR_11 	   0x62  
#define CONFIG_SENSOR_IIC_ADAPTER_ID_11    1  
#define CONFIG_SENSOR_CIF_INDEX_11				  0
#define CONFIG_SENSOR_ORIENTATION_11       270
#define CONFIG_SENSOR_POWER_PIN_11         INVALID_GPIO
#define CONFIG_SENSOR_RESET_PIN_11         INVALID_GPIO
#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
#define CONFIG_SENSOR_POWERDN_PIN_11       INVALID_GPIO//RK2928_PIN3_PB3
#else
#if defined(CONFIG_MACH_RK2928_SDK)
#define CONFIG_SENSOR_POWERDN_PIN_11       RK2928_PIN3_PD7
#else
#define CONFIG_SENSOR_POWERDN_PIN_11 	  RK2928_PIN3_PB3
#endif
#endif
#define CONFIG_SENSOR_FALSH_PIN_11         INVALID_GPIO
#define CONFIG_SENSOR_POWERACTIVE_LEVEL_11 RK29_CAM_POWERACTIVE_L
#define CONFIG_SENSOR_RESETACTIVE_LEVEL_11 RK29_CAM_RESETACTIVE_L
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_11 RK29_CAM_POWERDNACTIVE_H
#define CONFIG_SENSOR_FLASHACTIVE_LEVEL_11 RK29_CAM_FLASHACTIVE_L

#define CONFIG_SENSOR_QCIF_FPS_FIXED_11      15000
#define CONFIG_SENSOR_240X160_FPS_FIXED_11   15000
#define CONFIG_SENSOR_QVGA_FPS_FIXED_11      15000
#define CONFIG_SENSOR_CIF_FPS_FIXED_11       15000
#define CONFIG_SENSOR_VGA_FPS_FIXED_11       15000
#define CONFIG_SENSOR_480P_FPS_FIXED_11      15000
#define CONFIG_SENSOR_SVGA_FPS_FIXED_11      15000
#define CONFIG_SENSOR_720P_FPS_FIXED_11      30000

#define CONFIG_SENSOR_12 RK29_CAM_SENSOR_GC0308                      /* front camera sensor 2 */
#define CONFIG_SENSOR_IIC_ADDR_12 	   0x42
#define CONFIG_SENSOR_IIC_ADAPTER_ID_12    1
#define CONFIG_SENSOR_CIF_INDEX_12				  0
#define CONFIG_SENSOR_ORIENTATION_12       270
#define CONFIG_SENSOR_POWER_PIN_12         INVALID_GPIO
#define CONFIG_SENSOR_RESET_PIN_12         INVALID_GPIO

#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
#define CONFIG_SENSOR_POWERDN_PIN_12       INVALID_GPIO//RK2928_PIN3_PB3
#else
#if defined(CONFIG_MACH_RK2928_SDK)
#define CONFIG_SENSOR_POWERDN_PIN_12       RK2928_PIN3_PD7
#else
#define CONFIG_SENSOR_POWERDN_PIN_12 	  RK2928_PIN3_PB3
#endif
#endif
#define CONFIG_SENSOR_FALSH_PIN_12         INVALID_GPIO
#define CONFIG_SENSOR_POWERACTIVE_LEVEL_12 RK29_CAM_POWERACTIVE_L
#define CONFIG_SENSOR_RESETACTIVE_LEVEL_12 RK29_CAM_RESETACTIVE_L
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_12 RK29_CAM_POWERDNACTIVE_H
#define CONFIG_SENSOR_FLASHACTIVE_LEVEL_12 RK29_CAM_FLASHACTIVE_L

#define CONFIG_SENSOR_QCIF_FPS_FIXED_12      15000
#define CONFIG_SENSOR_240X160_FPS_FIXED_12   15000
#define CONFIG_SENSOR_QVGA_FPS_FIXED_12      15000
#define CONFIG_SENSOR_CIF_FPS_FIXED_12       15000
#define CONFIG_SENSOR_VGA_FPS_FIXED_12       15000
#define CONFIG_SENSOR_480P_FPS_FIXED_12      15000
#define CONFIG_SENSOR_SVGA_FPS_FIXED_12      15000
#define CONFIG_SENSOR_720P_FPS_FIXED_12      30000


#endif  //#ifdef CONFIG_VIDEO_RK29
/*---------------- Camera Sensor Configuration Macro End------------------------*/
#include "../../../drivers/media/video/rk2928_camera.c"
/*---------------- Camera Sensor Macro Define End  ---------*/

#define PMEM_CAM_SIZE PMEM_CAM_NECESSARY
/*****************************************************************************************
 * camera  devices
 * author: ddl@rock-chips.com
 *****************************************************************************************/
#ifdef CONFIG_VIDEO_RK29
#if defined(CONFIG_MACH_RK2926_V86)
    #ifdef  CONFIG_CAMERA_BACK_USE_GC0329_REPLACE_SP2518
#define CAMERA_NAME	              "gc0329_back"
   #else
#define CAMERA_NAME	              "sp2518_back"   
   #endif
#ifdef  CONFIG_CAMERA_BACK_USE_GC2035_REPLACE_SP0838
#define CAMERA_NAME1              "gc2035_back_1"
#else
#define CAMERA_NAME1              "sp0838_back_1"
#endif
#define CAMERA_NAME2              "gc0308_back_2"
#define CONFIG_SENSOR_POWERDNACTIVE_LEVEL_PMU  1
#define CONFIG_SENSOR_POWER_IOCTL_USR	         1
#define CONFIG_SENSOR_POWERDOWN_IOCTL_USR	   1
#else
#define CONFIG_SENSOR_POWER_IOCTL_USR	   0 //define this refer to your board layout
#define CONFIG_SENSOR_POWERDOWN_IOCTL_USR	   0
#endif
#define CONFIG_SENSOR_RESET_IOCTL_USR	   0
#define CONFIG_SENSOR_FLASH_IOCTL_USR	   0

static void rk_cif_power(int on)
{
    struct regulator *ldo_18,*ldo_28;

      #if defined(CONFIG_MACH_RK2926_V86)
      ldo_28 = regulator_get(NULL, "vaux1");	// vcc28_cif
	ldo_18 = regulator_get(NULL, "vdig1");	// vcc18_cif
      #else
	ldo_28 = regulator_get(NULL, "ldo7");	// vcc28_cif
	ldo_18 = regulator_get(NULL, "ldo1");	// vcc18_cif
	#endif
	if (ldo_28 == NULL || IS_ERR(ldo_28) || ldo_18 == NULL || IS_ERR(ldo_18)){
        printk("get cif ldo failed!\n");
		return;
	    }
    if(on == 0){
#ifndef CONFIG_SOC_CAMERA_SP0838
      while(regulator_is_enabled(ldo_28)>0)
    	    regulator_disable(ldo_28);
    	regulator_put(ldo_28);
    	while(regulator_is_enabled(ldo_18)>0)
    	    regulator_disable(ldo_18);
    	regulator_put(ldo_18);
    	mdelay(500);
#endif
        }
    else{
    	regulator_set_voltage(ldo_28, 2800000, 2800000);
    	regulator_enable(ldo_28);
   // 	printk("%s set ldo7 vcc28_cif=%dmV end\n", __func__, regulator_get_voltage(ldo_28));
    	regulator_put(ldo_28);

    	regulator_set_voltage(ldo_18, 1800000, 1800000);
    //	regulator_set_suspend_voltage(ldo, 1800000);
    	regulator_enable(ldo_18);
    //	printk("%s set ldo1 vcc18_cif=%dmV end\n", __func__, regulator_get_voltage(ldo_18));
    	regulator_put(ldo_18);
        }
}

#if CONFIG_SENSOR_POWER_IOCTL_USR
static int sensor_power_usr_cb (struct rk29camera_gpio_res *res,int on)
{
	//#error "CONFIG_SENSOR_POWER_IOCTL_USR is 1, sensor_power_usr_cb function must be writed!!";
    rk_cif_power(on);
}
#endif

#if CONFIG_SENSOR_RESET_IOCTL_USR
static int sensor_reset_usr_cb (struct rk29camera_gpio_res *res,int on)
{
	#error "CONFIG_SENSOR_RESET_IOCTL_USR is 1, sensor_reset_usr_cb function must be writed!!";
}
#endif

#if CONFIG_SENSOR_POWERDOWN_IOCTL_USR
static void rk_cif_powerdowen(int on)
{
    struct regulator *ldo_28;
    ldo_28 = regulator_get(NULL, "vpll");   // vcc28_cif
    if (ldo_28 == NULL || IS_ERR(ldo_28) ){
            printk("get cif vpll ldo failed!\n");
            return;
    }
    
    if( CONFIG_SENSOR_POWERDNACTIVE_LEVEL_PMU ) {
            if(on == 0){//enable camera
                   regulator_set_voltage(ldo_28, 2500000, 2500000);
                   regulator_enable(ldo_28);
                   printk(" %s set  vpll vcc28_cif=%dmV end\n", __func__, regulator_get_voltage(ldo_28));
                   regulator_put(ldo_28);
            }else{//disable camera
            	    while(regulator_is_enabled(ldo_28)>0){
                        int a = regulator_disable(ldo_28);
                  }
                  regulator_put(ldo_28);
                  mdelay(500);
            }
     }else{
            
            if(on == 1){//enable camera
                   regulator_set_voltage(ldo_28, 2500000, 2500000);
                   regulator_enable(ldo_28);
                   printk(" %s set  vpll vcc28_cif=%dmV end\n", __func__, regulator_get_voltage(ldo_28));
                   regulator_put(ldo_28);
            }else{//disable camera
            	    while(regulator_is_enabled(ldo_28)>0){
                        regulator_disable(ldo_28);
                  }
                  regulator_put(ldo_28);
                  mdelay(500);
            }
     }
}
static int sensor_powerdown_usr_cb (struct rk29camera_gpio_res *res,int on)
{
    #if defined(CONFIG_MACH_RK2926_V86)
    int ret = 0; 
    
   //  printk("%s.......%s......lizhengwei\n",res->dev_name,CAMERA_NAME);
#ifdef CONFIG_CAMERA_PMU_GPIO_RESEVRT
    if((strcmp(res->dev_name,CAMERA_NAME)==0)||
       (strcmp(res->dev_name,CAMERA_NAME1)==0) ||
       (strcmp(res->dev_name,CAMERA_NAME2)==0))
   { //gpio控制的操作
            int camera_powerdown = res->gpio_powerdown;
            int camera_ioflag = res->gpio_flag;
            int camera_io_init = res->gpio_init; //  int ret = 0;    
            if (camera_powerdown != INVALID_GPIO) { 
                    if (camera_io_init & RK29_CAM_POWERDNACTIVE_MASK) {
                          if (on) {
                                gpio_set_value(camera_powerdown, ((camera_ioflag&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                                printk("%s..%s..PowerDownPin=%d ..PinLevel = %x \n",__FUNCTION__,res->dev_name,camera_powerdown, ((camera_ioflag&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                         } else { 
                                gpio_set_value(camera_powerdown,(((~camera_ioflag)&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                                printk("%s..%s..PowerDownPin= %d..PinLevel = %x   \n",__FUNCTION__,res->dev_name, camera_powerdown, (((~camera_ioflag)&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                         }
                  } else { ret = RK29_CAM_EIO_REQUESTFAIL;
                                printk("%s..%s..PowerDownPin=%d request failed!\n",__FUNCTION__,res->dev_name,camera_powerdown); } 
          } else { 
                ret = RK29_CAM_EIO_INVALID; 
          }
    }
    else
     { 
        //如果为pmu控制的引脚，"ov5642_front_1" 根据 sensor名字 ，前后置 ， sensor序号确定 
        //具体pmu控制操作，可参考文件末尾的参考代码 
        printk("%s.............pwm power\n",__FUNCTION__);
        rk_cif_powerdowen(on);
    }
#else   
     if((strcmp(res->dev_name,CAMERA_NAME)==0)||
       (strcmp(res->dev_name,CAMERA_NAME1)==0) ||
       (strcmp(res->dev_name,CAMERA_NAME2)==0))
    { 
        //如果为pmu控制的引脚，"ov5642_front_1" 根据 sensor名字 ，前后置 ， sensor序号确定 
        //具体pmu控制操作，可参考文件末尾的参考代码 
        printk("%s.............pwm power\n",__FUNCTION__);
        rk_cif_powerdowen(on);
    }else{ //gpio控制的操作
            int camera_powerdown = res->gpio_powerdown;
            int camera_ioflag = res->gpio_flag;
            int camera_io_init = res->gpio_init; //  int ret = 0;    
            if (camera_powerdown != INVALID_GPIO) { 
                    if (camera_io_init & RK29_CAM_POWERDNACTIVE_MASK) {
                          if (on) {
                                gpio_set_value(camera_powerdown, ((camera_ioflag&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                                printk("%s..%s..PowerDownPin=%d ..PinLevel = %x \n",__FUNCTION__,res->dev_name,camera_powerdown, ((camera_ioflag&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                         } else { 
                                gpio_set_value(camera_powerdown,(((~camera_ioflag)&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                                printk("%s..%s..PowerDownPin= %d..PinLevel = %x   \n",__FUNCTION__,res->dev_name, camera_powerdown, (((~camera_ioflag)&RK29_CAM_POWERDNACTIVE_MASK)>>RK29_CAM_POWERDNACTIVE_BITPOS)); 
                         }
                  } else { ret = RK29_CAM_EIO_REQUESTFAIL;
                                printk("%s..%s..PowerDownPin=%d request failed!\n",__FUNCTION__,res->dev_name,camera_powerdown); } 
          } else { 
                ret = RK29_CAM_EIO_INVALID; 
          }
    }
#endif    
    return ret;
    #else
    #error "CONFIG_SENSOR_POWERDOWN_IOCTL_USR is 1, sensor_powerdown_usr_cb function must be writed!!";
    #endif
}
#endif

#if CONFIG_SENSOR_FLASH_IOCTL_USR
static int sensor_flash_usr_cb (struct rk29camera_gpio_res *res,int on)
{
	#error "CONFIG_SENSOR_FLASH_IOCTL_USR is 1, sensor_flash_usr_cb function must be writed!!";
}
#endif

static struct rk29camera_platform_ioctl_cb	sensor_ioctl_cb = {
	#if CONFIG_SENSOR_POWER_IOCTL_USR
	.sensor_power_cb = sensor_power_usr_cb,
	#else
	.sensor_power_cb = NULL,
	#endif

	#if CONFIG_SENSOR_RESET_IOCTL_USR
	.sensor_reset_cb = sensor_reset_usr_cb,
	#else
	.sensor_reset_cb = NULL,
	#endif

	#if CONFIG_SENSOR_POWERDOWN_IOCTL_USR
	.sensor_powerdown_cb = sensor_powerdown_usr_cb,
	#else
	.sensor_powerdown_cb = NULL,
	#endif

	#if CONFIG_SENSOR_FLASH_IOCTL_USR
	.sensor_flash_cb = sensor_flash_usr_cb,
	#else
	.sensor_flash_cb = NULL,
	#endif
};

#if CONFIG_SENSOR_IIC_ADDR_0
static struct reginfo_t rk_init_data_sensor_reg_0[] =
{
		{0x0000, 0x00,0,0}
	};
static struct reginfo_t rk_init_data_sensor_winseqreg_0[] ={
	{0x0000, 0x00,0,0}
	};
#endif

#if CONFIG_SENSOR_IIC_ADDR_1
static struct reginfo_t rk_init_data_sensor_reg_1[] =
{
    {0x0000, 0x00,0,0}
};
static struct reginfo_t rk_init_data_sensor_winseqreg_1[] =
{
       {0x0000, 0x00,0,0}
};
#endif
#if CONFIG_SENSOR_IIC_ADDR_01
static struct reginfo_t rk_init_data_sensor_reg_01[] =
{
    {0x0000, 0x00,0,0}
};
static struct reginfo_t rk_init_data_sensor_winseqreg_01[] =
{
       {0x0000, 0x00,0,0}
};
#endif
#if CONFIG_SENSOR_IIC_ADDR_02
static struct reginfo_t rk_init_data_sensor_reg_02[] =
{
    {0x0000, 0x00,0,0}
};
static struct reginfo_t rk_init_data_sensor_winseqreg_02[] =
{
       {0x0000, 0x00,0,0}
};
#endif
#if CONFIG_SENSOR_IIC_ADDR_11
static struct reginfo_t rk_init_data_sensor_reg_11[] =
{
    {0x0000, 0x00,0,0}
};
static struct reginfo_t rk_init_data_sensor_winseqreg_11[] =
{
       {0x0000, 0x00,0,0}
};
#endif
#if CONFIG_SENSOR_IIC_ADDR_12
static struct reginfo_t rk_init_data_sensor_reg_12[] =
{
    {0x0000, 0x00,0,0}
};
static struct reginfo_t rk_init_data_sensor_winseqreg_12[] =
{
       {0x0000, 0x00,0,0}
};
#endif
static rk_sensor_user_init_data_s rk_init_data_sensor[RK_CAM_NUM] = 
{
    #if CONFIG_SENSOR_IIC_ADDR_0
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = rk_init_data_sensor_reg_0,
       .rk_sensor_init_winseq = rk_init_data_sensor_winseqreg_0,
       .rk_sensor_winseq_size = sizeof(rk_init_data_sensor_winseqreg_0) / sizeof(struct reginfo_t),
       .rk_sensor_init_data_size = sizeof(rk_init_data_sensor_reg_0) / sizeof(struct reginfo_t),
    },
    #else
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = NULL,
       .rk_sensor_init_winseq = NULL,
       .rk_sensor_winseq_size = 0,
       .rk_sensor_init_data_size = 0,
    },
    #endif
    #if CONFIG_SENSOR_IIC_ADDR_1
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = rk_init_data_sensor_reg_1,
       .rk_sensor_init_winseq = rk_init_data_sensor_winseqreg_1,
       .rk_sensor_winseq_size = sizeof(rk_init_data_sensor_winseqreg_1) / sizeof(struct reginfo_t),
       .rk_sensor_init_data_size = sizeof(rk_init_data_sensor_reg_1) / sizeof(struct reginfo_t),
    },
    #else
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = NULL,
       .rk_sensor_init_winseq = NULL,
       .rk_sensor_winseq_size = 0,
       .rk_sensor_init_data_size = 0,
    },
    #endif
    #if CONFIG_SENSOR_IIC_ADDR_01
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = rk_init_data_sensor_reg_01,
       .rk_sensor_init_winseq = rk_init_data_sensor_winseqreg_01,
       .rk_sensor_winseq_size = sizeof(rk_init_data_sensor_winseqreg_01) / sizeof(struct reginfo_t),
       .rk_sensor_init_data_size = sizeof(rk_init_data_sensor_reg_01) / sizeof(struct reginfo_t),
    },
    #else
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = NULL,
       .rk_sensor_init_winseq = NULL,
       .rk_sensor_winseq_size = 0,
       .rk_sensor_init_data_size = 0,
    },
    #endif
    #if CONFIG_SENSOR_IIC_ADDR_02
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = rk_init_data_sensor_reg_02,
       .rk_sensor_init_winseq = rk_init_data_sensor_winseqreg_02,
       .rk_sensor_winseq_size = sizeof(rk_init_data_sensor_winseqreg_02) / sizeof(struct reginfo_t),
       .rk_sensor_init_data_size = sizeof(rk_init_data_sensor_reg_02) / sizeof(struct reginfo_t),
    },
    #else
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = NULL,
       .rk_sensor_init_winseq = NULL,
       .rk_sensor_winseq_size = 0,
       .rk_sensor_init_data_size = 0,
    },
    #endif
    #if CONFIG_SENSOR_IIC_ADDR_11
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = rk_init_data_sensor_reg_11,
       .rk_sensor_init_winseq = rk_init_data_sensor_winseqreg_11,
       .rk_sensor_winseq_size = sizeof(rk_init_data_sensor_winseqreg_11) / sizeof(struct reginfo_t),
       .rk_sensor_init_data_size = sizeof(rk_init_data_sensor_reg_11) / sizeof(struct reginfo_t),
    },
    #else
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = NULL,
       .rk_sensor_init_winseq = NULL,
       .rk_sensor_winseq_size = 0,
       .rk_sensor_init_data_size = 0,
    },
    #endif
    #if CONFIG_SENSOR_IIC_ADDR_12
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = rk_init_data_sensor_reg_12,
       .rk_sensor_init_winseq = rk_init_data_sensor_winseqreg_12,
       .rk_sensor_winseq_size = sizeof(rk_init_data_sensor_winseqreg_12) / sizeof(struct reginfo_t),
       .rk_sensor_init_data_size = sizeof(rk_init_data_sensor_reg_12) / sizeof(struct reginfo_t),
    },
    #else
    {
       .rk_sensor_init_width = INVALID_VALUE,
       .rk_sensor_init_height = INVALID_VALUE,
       .rk_sensor_init_bus_param = INVALID_VALUE,
       .rk_sensor_init_pixelcode = INVALID_VALUE,
       .rk_sensor_init_data = NULL,
       .rk_sensor_init_winseq = NULL,
       .rk_sensor_winseq_size = 0,
       .rk_sensor_init_data_size = 0,
    },
    #endif

 };
#include "../../../drivers/media/video/rk2928_camera.c"

#endif /* CONFIG_VIDEO_RK29 */

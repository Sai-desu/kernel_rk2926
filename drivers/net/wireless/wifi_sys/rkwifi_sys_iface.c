
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/err.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37))
static ssize_t wifi_chip_read(struct class *cls, struct class_attribute *attr, char *_buf)
#else
static ssize_t wifi_chip_read(struct class *cls, char *_buf)
#endif
{
    int count = 0;

#ifdef CONFIG_BCM4329
    count = sprintf(_buf, "%s", "BCM4329");
    printk("Current WiFi chip is BCM4329.\n");
#endif

#ifdef CONFIG_RTL8192CU
    count = sprintf(_buf, "%s", "RTL8188CU");
    printk("Current WiFi chip is RTL8188CU.\n");
#endif

#ifdef CONFIG_RTL8188EU
    count = sprintf(_buf, "%s", "RTL8188EU");
    printk("Current WiFi chip is RTL8188EU.\n");
#endif

#ifdef CONFIG_BCM4330
    count = sprintf(_buf, "%s", "BCM4330");
    printk("Current WiFi chip is BCM4330.\n");
#endif

#ifdef CONFIG_RK901
    count = sprintf(_buf, "%s", "RK901");
    printk("Current WiFi chip is RK901.\n");
#endif

#ifdef CONFIG_RK903
    count = sprintf(_buf, "%s", "RK903");
    printk("Current WiFi chip is RK903.\n");
#endif
    
#ifdef CONFIG_RT5370
    count = sprintf(_buf, "%s", "RT5370");
    printk("Current WiFi chip is RT5370.\n");
#endif

#ifdef CONFIG_MT5931
    count = sprintf(_buf, "%s", "MT5931");
    printk("Current WiFi chip is MT5931.\n");
#endif

#ifdef CONFIG_MT5931_MT6622
    count = sprintf(_buf, "%s", "MT5931");
    printk("Current WiFi chip is MT5931.\n");
#endif

    return count;
}

/*
static ssize_t wifi_channel_write(struct class *cls, const char *_buf, size_t _count)
{
    int ret, channel;
    
    if (wifi_enabled == 0)
    {
        printk("WiFi is disabled.\n");
        return _count;
    }
    
    channel = simple_strtol(_buf, NULL, 10);
    
    ret = wifi_emi_set_channel(channel);
    if (ret != 0)
    {
        //printk("Set channel=%d fail.\n", channel);
    }
    else
    {
        //printk("Set channel=%d successfully.\n", channel);
        wifi_channel = channel;
    }
    
    return _count;
}
*/

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37))
static ssize_t wifi_p2p_read(struct class *cls, struct class_attribute *attr, char *_buf)
#else
static ssize_t wifi_p2p_read(struct class *cls, char *_buf)
#endif
{
	int count = 0;

#ifdef CONFIG_BCM4329
    count = sprintf(_buf, "%s", "false");
	printk("Current WiFi chip BCM4329 doesn't support direct.(%s)\n", _buf);
#endif

#ifdef CONFIG_RTL8192CU
    count = sprintf(_buf, "%s", "false");
	printk("Current WiFi chip RTL8188 support direct.(%s)\n", _buf);
#endif

#ifdef CONFIG_RK903
    count = sprintf(_buf, "%s", "true");
	    printk("Current WiFi chip RK903 support direct.(%s)\n", _buf);
#endif

#ifdef CONFIG_BCM4330
    count = sprintf(_buf, "%s", "true");
	printk("Current WiFi chip BCM4330 support direct.(%s)\n", _buf);
#endif

	return count;
}

int wifi_pcba_test = 0;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37))
static ssize_t wifi_pcba_read(struct class *cls, struct class_attribute *attr, char *_buf)
#else
static ssize_t wifi_pcba_read(struct class *cls, char *_buf)
#endif
{
        int count = 0;

        count = sprintf(_buf, "%d", wifi_pcba_test);
        return count;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37))
static ssize_t wifi_pcba_write(struct class *cls, struct class_attribute *attr, char *_buf, size_t _count)
#else
static ssize_t wifi_pcba_write(struct class *cls, char *_buf, size_t _count)
#endif 
{
        wifi_pcba_test = simple_strtol(_buf, NULL, 10);
        if(wifi_pcba_test > 0) {
            wifi_pcba_test = 1;
        }
        return _count;
}

static struct class *rkwifi_class = NULL;
static CLASS_ATTR(chip, 0664, wifi_chip_read, NULL);
static CLASS_ATTR(p2p, 0664, wifi_p2p_read, NULL);
static CLASS_ATTR(pcba, 0664, wifi_pcba_read, wifi_pcba_write);

int rkwifi_sysif_init(void)
{
    int ret;
    
    printk("Rockchip WiFi SYS interface (V1.00) ... \n");
    
    rkwifi_class = NULL;
    
    rkwifi_class = class_create(THIS_MODULE, "rkwifi");
    if (IS_ERR(rkwifi_class)) 
    {   
        printk("Create class rkwifi_class failed.\n");
        return -ENOMEM;
    }
    
    ret =  class_create_file(rkwifi_class, &class_attr_chip);
    ret =  class_create_file(rkwifi_class, &class_attr_p2p);
    ret =  class_create_file(rkwifi_class, &class_attr_pcba);
    
    return 0;
}

void rkwifi_sysif_exit(void)
{
    // need to remove the sys files and class
    class_remove_file(rkwifi_class, &class_attr_chip);
    class_remove_file(rkwifi_class, &class_attr_p2p);
    class_remove_file(rkwifi_class, &class_attr_pcba);
    class_destroy(rkwifi_class);
    
    rkwifi_class = NULL;
}

module_init(rkwifi_sysif_init);
module_exit(rkwifi_sysif_exit);

MODULE_AUTHOR("Yongle Lai");
MODULE_DESCRIPTION("WiFi SYS @ Rockchip");
MODULE_LICENSE("GPL");


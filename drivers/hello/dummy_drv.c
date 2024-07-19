#include <linux/module.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/printk.h>

#include "dummy_drv.h"

#define DRV_NAME "HELLO_DRV"
#define DRV_MODULE_VERSION "1.0"
#define DRV_MODULE_AUTHOR "Shanaka"
#define DRV_MODULE_DESCRIPTION "Test driver with kernel messages"

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR(DRV_MODULE_AUTHOR);
MODULE_DESCRIPTION(DRV_MODULE_DESCRIPTION);
MODULE_VERSION(DRV_MODULE_VERSION);


static int __init dummy_init(void){
	printk("%s()\n", __func__);
	printk(KERN_NOTICE "Loading " DRV_NAME " Driver \n");
	return 0;
}

static void __exit dummy_exit(void){
	printk("%s()\n", __func__);
	printk(KERN_NOTICE "Unloading " DRV_NAME " Driver \n");
}

module_init(dummy_init);
module_exit(dummy_exit);
  
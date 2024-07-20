#include <linux/module.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/printk.h>

#include "dummy_drv.h"

#define DRV_NAME "DUMMY_DRV"
#define DRV_MODULE_VERSION "1.0"
#define DRV_MODULE_AUTHOR "Shanaka"
#define DRV_MODULE_DESCRIPTION "Test driver with kernel messages"

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR(DRV_MODULE_AUTHOR);
MODULE_DESCRIPTION(DRV_MODULE_DESCRIPTION);
MODULE_VERSION(DRV_MODULE_VERSION);


/**
 * @brief This function notify when the device driver file is open from userland
 * @param struct inode pointer to device_file instance
 * @param struct file pointer to a file instance
 * @return int 0-success
 */
static int user_device_open(struct *device_file, struct file *instance){
	printk(KERN_NOTICE "Device /dev/file was opened\n")
	return 0;
}

/**
 * @brief This function notify when the device driver file is closed from userland
 * @param struct inode pointer to device_file instance
 * @param struct file pointer to a file instance
 * @return int 0-success
 */
static int user_device_release(struct *device_file, struct file *instance){
	printk(KERN_NOTICE "Device /dev/file was closed\n")
	return 0;
}

/** 
 * @brief structure to save the file operations functions
 * @param owner owner of the operation
 * @param open open operation function
 * @param release release operation function
*/
static struct file_operations file_ops = {
	.owner = THIS_MODULE,
	.open = user_device_open,
	.release = user_device_release,
};

/**
 * @brief this function initialize the module
 * @return int 0-success 1-failure
*/
static int __init dummy_init(void){
	printk("%s()\n", __func__);
	printk(KERN_NOTICE "Loading " DRV_NAME " Driver \n");
	// register the device to userland
	// TODO 
	return 0;
}

/**
 * @brief this function remove the module
 * @return int 0-success 1-failure
*/
static void __exit dummy_exit(void){
	printk("%s()\n", __func__);
	printk(KERN_NOTICE "Unloading " DRV_NAME " Driver \n");
}

/**
 * Configure module initialization and exit functions
 */
module_init(dummy_init);
module_exit(dummy_exit);
  
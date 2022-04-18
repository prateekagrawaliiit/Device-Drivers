/*
* @Author: prateekagrawaliiit
* @Date:   2022-04-13 14:57:32
* @Last Modified by:   prateekagrawaliiit
* @Last Modified time: 2022-04-13 14:58:13
*/

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>                 //kmalloc()
#include <linux/uaccess.h>              //copy_to/from_user()
#include <linux/ioctl.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

int32_t value = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev my_cdev;

/*
** Function Prototypes
*/
static int      __init driver_init_function(void);
static void     __exit driver_exit_function(void);
static long     my_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/*
** File operation sturcture
*/
static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .unlocked_ioctl = my_ioctl,
};

/*
** This function will be called when we write IOCTL on the Device file
*/
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
        switch (cmd) {
        case WR_VALUE:
                if ( copy_from_user(&value , (int32_t*) arg, sizeof(value)) )
                {
                        pr_err("Data Write : Err!\n");
                }
                pr_info("Value = %d\n", value);
                break;
        case RD_VALUE:
                if ( copy_to_user((int32_t*) arg, &value, sizeof(value)) )
                {
                        pr_err("Data Read : Err!\n");
                }
                break;
        default:
                pr_info("Default\n");
                break;
        }
        return 0;
}

/*
** Module Init function
*/
static int __init driver_init_function(void)
{
        /*Allocating Major number*/
        if ((alloc_chrdev_region(&dev, 0, 1, "my_Dev")) < 0) {
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n", MAJOR(dev), MINOR(dev));
        /*Creating cdev structure*/
        cdev_init(&my_cdev, &fops);
        /*Adding character device to the system*/
        if ((cdev_add(&my_cdev, dev, 1)) < 0) {
                pr_err("Cannot add the device to the system\n");
                goto r_class;
        }
        /*Creating struct class*/
        if ((dev_class = class_create(THIS_MODULE, "my_class")) == NULL) {
                pr_err("Cannot create the struct class\n");
                goto r_class;
        }
        /*Creating device*/
        if ((device_create(dev_class, NULL, dev, NULL, "mychardev")) == NULL) {
                pr_err("Cannot create the Device 1\n");
                goto r_device;
        }
        pr_info("Device Driver Insert...Done!!!\n");
        return 0;
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev, 1);
        return -1;
}

static void __exit driver_exit_function(void)
{
        device_destroy(dev_class, dev);
        class_destroy(dev_class);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!!\n");
}

module_init(driver_init_function);
module_exit(driver_exit_function);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prateek Agrawal - CED18I040");
MODULE_DESCRIPTION("Device Driver Lab End Sem");
MODULE_VERSION("1.5");
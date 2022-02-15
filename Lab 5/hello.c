/*
* @Author: prateekagrawaliiit
* @Date:   2022-02-15 16:20:35
* @Last Modified by:   prateekagrawaliiit
* @Last Modified time: 2022-02-15 16:34:36
*/

#include <linux/module.h>    /* Needed by all modules */
#include <linux/kernel.h>    /* Needed for KERN_INFO */
#include <linux/init.h>  /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Prateek Agrawal");

///< The description -- see modinfo
MODULE_DESCRIPTION("A simple Hello world kernel module!");

static int __init hello_start(void)
{
   printk(KERN_INFO "Loading Hello World Module\n");
   printk(KERN_INFO "Hello world\n");
   return 0;
}

static void __exit hello_end(void)
{
   printk(KERN_INFO "Goodbye !!!\n");
}

module_init(hello_start);
module_exit(hello_end);

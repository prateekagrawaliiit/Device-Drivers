#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xf4161c9f, "cdev_init" },
	{ 0x56470118, "__warn_printk" },
	{ 0xf595d267, "device_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xc5645b17, "class_unregister" },
	{ 0xd9da0486, "device_create" },
	{ 0xc0fdf3d5, "cdev_add" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa946dcde, "__class_create" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x9c6febfc, "add_uevent_var" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BA77623BA9FACCB04527E0A");

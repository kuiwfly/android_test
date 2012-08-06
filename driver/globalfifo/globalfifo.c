#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
MODULE_AUTHOR("wk") ;
MODULE_LICENSE("Dual BSD/GPL") ;

static int globalfifo_ioctl(struct inode *inode ,struct file *file,
	unsigned int cmd ,unsigned long arg)
{
	return 0 ;
}
static ssize_t globalfifo_read(struct file *filp, char __user *buf,
	size_t size, loff_t *ppos)
{
	printk("read from fifo\n") ;
	return 0 ;
}
static ssize_t globalfifo_write(struct file *filp, const char __user *buf,
	size_t size, loff_t *ppos)
{
	printk("write to fifo!\n") ;
	return 0 ;
}

static struct file_operations globalfifo_fops = {
	.owner = THIS_MODULE ,
	.ioctl = globalfifo_ioctl ,
	.read = globalfifo_read ,
	.write = globalfifo_write ,
} ;

static struct miscdevice globalfifo_misc = {
	.minor = MISC_DYNAMIC_MINOR ,
	.name = "Global Fifo",
	.fops = &globalfifo_fops,
} ;

static int __init globalfifo_probe(struct platform_device *pdev)
{
	misc_register(&globalfifo_misc) ;
	printk("register globalfifo!\n") ;
	return 0 ;
}
static int __exit globalfifo_remove(struct platform_device *pdev)
{
	misc_deregister(&globalfifo_misc) ;
	printk("unregister globalfifo !\n") ;
}
static struct platform_driver globalfifo_driver = {
	.probe = globalfifo_probe ,
	.remove = globalfifo_remove ,
	.driver = {
		.name = "Global Fifo",
		.owner = THIS_MODULE ,
	}
} ;

static int __init globalfifo_init(void)
{
	return platform_driver_register(&globalfifo_driver) ;
}

static void __exit globalfifo_exit(void)
{
	platform_driver_unregister(&globalfifo_driver) ;
}
module_init(globalfifo_init) ;
module_exit(globalfifo_exit) ;

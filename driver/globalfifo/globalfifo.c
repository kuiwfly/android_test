#include <linux/module.h>//support module load and unload
#include <linux/types.h>//special type definition,like dev_t off_t defined by typedef
#include <linux/fs.h>//struct file_operations
#include <linux/errno.h>//return value 
#include <linux/mm.h>//memory mannage ,include kmalloc.kfree and so on
#include <linux/sched.h>//process schedule 
#include <linux/init.h>//
#include <linux/cdev.h>//char device structure definition
#include <linux/io.h>//io operation function ,like ioremap,iowrite
#include <linux/poll.h>


#define GLOBALFIFO_SIZE 0x1000 //1M
#define CLEAR_ALL 0x01 //clear fifo 
#define GLOBALFIFO_MAJOR 253//major device No

static int globalfifo_major = GLOBALFIFO_MAJOR  ;
/*define globalfifo structure*/
struct globalfifo_dev {
	struct cdev dev ;
	unsigned int current_len ;
	unsigned char mem[GLOBALFIFO_SIZE] ;
	struct semaphore sem ;
	wait_queue_head_t r_wait ;
	wait_queue_head_t w_wait ;
} ;
struct globalfifo_dev *globalfifo_devp ;

int globalfifo_open(struct inode *inode, struct file *filp)
{
	filp->private_data = globalfifo_devp ;
	return 0 ;
}
int globalfifo_release(struct inode *inode ,struct file *filp)
{
	return 0 ;
}
#if KERNEL_OLD
static int globalfifo_ioctl(struct inode *inode, struct file *filp,
	int cmd, unsigned long arg)
{
	struct globalfifo_dev *dev = filp->private_data ;
	switch (cmd)
	{
		case CLEAR_ALL:
			/*note:down_intterruptible is more suitable,why?*/
			down_interruptible(&dev->sem) ;
			dev->current_len = 0 ;
			memset(dev->mem,0,GLOBALFIFO_SIZE) ;
			up(dev->sem) ;
			printk(KERN_INFO "clear globalfifo successfully!\n") ;
			break ;
		default:
			printk(KERN_INFO "invalid command!\n") ;
			return -EINVAL ;
	}
}
#else
#endif
static unsigned int globalfifo_poll(struct file *filp, poll_table *wait)
{
	unsigned int mask = 0 ;
	struct globalfifo_dev *dev = filp->private_data ;
	
	down_interruptible(&dev->sem) ;
	
	poll_wait(filp,&dev->r_wait,wait) ;
	poll_wait(filp,&dev->w_wait,wait) ;

	if(dev->current_len !=0 )
	{
		mask |= POLLIN | POLLRDNORM ;
	}
	if(dev->current_len< GLOBALFIFO_SIZE )
	{
		mask |= POLLOUT | POLLWRNORM ;
	}
	up(&dev->sem) ;
	return mask ;
}
static ssize_t globalfifo_read(struct file *filp, char __user *buf,
	size_t count, loff_t *ppos)
{
	int ret ;
	struct globalfifo_dev *dev = filp->private_data ;
	DECLARE_WAITQUEUE(wait,current) ;
	down_interruptible(&dev->sem) ;
	add_wait_queue(&dev->r_wait,&wait) ;
	if(dev->current_len == 0 )
	{
		if( filp->f_flags & O_NONBLOCK)
		{
			ret = -EAGAIN ;
			goto out ;
		}
		__set_current_state(TASK_INTERRUPTIBLE) ;
		up(&dev->sem) ;
		schedule() ;
		if(signal_pending(current))
		{
			ret = - ERESTARTSYS ;
			goto out2 ;
		}
		down_interruptible(&dev->sem) ;
	}
	if(count>dev->current_len)
	{
		count = dev->current_len ;
	}
	if(copy_to_user(buf,dev->mem,count))
	{
		ret = -EFAULT ;
		goto out ;
	}else
	{
		memcpy(dev->mem,dev->men+count,dev->current_len-count) ;
		dev->current_len -= count ;
		printk(KERN_INFO "read %d bytes(s),current_len:%d\n",
			count,dev->current_len) ;
		wait_up_interruptible(&dev->w_wait) ;
		ret = count  ;
	}
out:
	up(&dev->sem) ;
out2:
	remove_wait_queue(&dev->w_wait,&wait) ;
	set_current_state(TASK_RUNNING) ;
	return ret ;
}
static ssize_t globalfifo_write(struct file *filp, const char __user *buf,
	size_t count, loff-t *ppos0
{
	struct globalfifo_dev *dev = filp->private_data ;
	int ret = -1 ;
	DECLARE_WAITQUEUE(wait,current) ;
			
	
}

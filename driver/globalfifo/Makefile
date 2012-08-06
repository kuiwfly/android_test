arch=arm
CC=arm-eabi-gcc
KDIR=/root/workspace/kernel/goldfish
ifneq ($(KERNELRELEASE),)
	obj-m := globalfifo.o
else
	PWD=$(shell pwd)
module:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
endif 
clean:
	rm -fr *.ko *.mod.c *.o *.order *.symvers

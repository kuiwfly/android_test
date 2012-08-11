ifneq ($(KERNELRELEASE),)
	obj-m := globalfifo.o
else
	KDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
endif
clean:
	rm -rf *.o *~ .depend *.ko  *.order *.symvers *.mod.c

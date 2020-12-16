obj-m = led_module.o

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

default: 
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)


DRIVER_NAME = hello
obj-m := $(DRIVER_NAME).o

$(DRIVER_NAME)-objs := dummy_drv.o

all: module

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	rm -f writer

check: all
	lsmod | grep $(DRIVER_NAME) || $(MAKE) insmod

insmod:
	sudo insmod $(DRIVER_NAME).ko

rmmod:
	sudo rmmod $(DRIVER_NAME)
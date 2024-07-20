# setup driver env variables
DRIVER_NAME = dummy_drv
obj-m := $(DRIVER_NAME).o

# all build target builds the modules
all: module

# custom build command to build module target to build kernel module
module:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

# clean kernel module build outputs
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

# build target all and verify the kernel module is loaded to the system or load it
check: all
	lsmod | grep $(DRIVER_NAME) || $(MAKE) insmod

# target to insert kernel module to system
insmod:
	sudo insmod $(DRIVER_NAME).ko

# target to remove kernel module from system
rmmod:
	sudo rmmod $(DRIVER_NAME)
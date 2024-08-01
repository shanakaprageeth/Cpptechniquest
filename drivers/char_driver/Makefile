# setup driver env variables
DRIVER_NAME = dummy_drv
obj-m := $(DRIVER_NAME).o

# all build target builds the modules
all: module build_dev_reader

# custom build command to build module target to build kernel module
module:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

# clean kernel module build outputs
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	rm user_read_device

# build target all and verify the kernel module is loaded to the system or load it
check: all
	lsmod | grep $(DRIVER_NAME) || $(MAKE) insmod

# target to insert kernel module to system
insmod:
	sudo insmod $(DRIVER_NAME).ko


# target to remove kernel module from system
rmmod:
	sudo rmmod $(DRIVER_NAME) || true

# target to create dummy device on userland for static device test
#add_device:
#	sudo mknod /dev/dummy_device c 99 0

# target to create dummy device on userland
build_dev_reader:
	gcc user_read_device.c -o user_read_device

#target write/read the device
rw_device:
	sleep 1
	sudo chmod 666 /dev/dummy_device
	echo "test passed" > /dev/dummy_device
	head -n 1 /dev/dummy_device

# target test device
test: all rmmod insmod rw_device rmmod


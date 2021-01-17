obj-y := hello.o
 
PWD := $(shell pwd)
KDIR := /mnt/linux/git/
 
all:
	make -C $(KDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=/mnt/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
 
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions

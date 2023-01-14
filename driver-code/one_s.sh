	clear
	cd ~/linux
	rm ~/linux/arch/riscv/boot/Image
	make -j$(nproc)
	make modules -j$(nproc)
	sudo make modules_install
	sudo make headers_install ARCH=riscv INSTALL_HDR_PATH=/usr
	rm ~/renode_portable/bins/Image
	cp ~/linux/arch/riscv/boot/Image ~/renode_portable/bins/
	cd ~/buildroot/output/host/bin 
	./riscv32-linux-gcc ~/renode_portable/bins/ioctl_app.c -march=rv32g -mabi=ilp32 -o ioctl_app.o -I ~/linux/drivers/misc/
	cd ~/renode_portable/bins
	rm ~/renode_portable/bins/rootfs -r
	mkdir rootfs && cd rootfs
	cd ~/renode_portable/bins/rootfs
	cat ../rootfs.cpio | cpio -idmv
	cp ~/linux/drivers/misc/my_driver* ~/renode_portable/bins/rootfs/root
	cp ~/buildroot/output/host/bin/ioctl_app.o  ~/renode_portable/bins/rootfs/root
	find . | cpio -o -H newc -R root:root > ../rootfs.cpio
	cd ~/linux
	

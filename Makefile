obj-m +=exp_mod.o 
obj-m +=dep_mod.o           

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


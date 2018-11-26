File : hello.c
Description :
		This programs explain concept of module dependency.
               1.First module namely exp_mod is for making a function available for others to use.
               2.second module namely dep_mod will give idea that how to use functions given by other modules.
                 

		
Steps to compile :
1.Run				                          			make
2.copy both modules into /lib/modules/'uname -r'          			sudo cp exp_mod.ko dep_mod.ko  /lib/modules/'uname -r'
3.Create dependency among the dependent modules using below command             sudo depmod -a
4.Run modprobe command                 						sudo modprobe exp_mod
5.See the logs in dmesg 		                  			dmesg | tail -1
  kernel ring buffer		
6.Remove dependent module	              					sudo rmmod dep_mod
7.See the logs in dmesg 		      					dmesg | tail -1
  kernel ring buffer          
8.Remove exporting module	              					sudo rmmod exp_mod       
9.see the logs in dmesg 		             				dmesg | tail -1
   kernel ring buffer         
10.Run				              					make clean


Note: For better practice change the sequence of inserting and removing the modules.

Keypoints to remember:
1.In Exporting file
-EXPORT_SYMBOL(a);
2.In dependent file
-extern a;

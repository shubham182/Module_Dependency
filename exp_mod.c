/************************************************************************************************
@fileName : exp_mod.c
@author   : Shubham Langde
@teamLead : Rajesh Dommaraju
@etails   : It is a driver for making a function, variables available for others to use.
@icense   : SpanIdea Systems Pvt. Ltd. All rights reserved.
************************************************************************************************/

/*******************************************************************************
			INCLUDES
*******************************************************************************/

#include <linux/init.h>
#include <linux/module.h>

/*******************************************************************************
			 LOCAL MACROS		
*******************************************************************************/

#define GPL_LICENSE				"GPL"
#define DRIVER_MODULE_AUTHOR			"SPANIDEA"
#define DRIVER_MODULE_DESC			"dependency Module"
#define DRIVER_MODULE_VERSION			"V1.0"

/*******************************************************************************
			 LOCAL TYPEDEFS		
*******************************************************************************/

/*******************************************************************************
			GLOBAL VARIABLES		
*******************************************************************************/
int gVar = 1000;
EXPORT_SYMBOL(gVar);

/*******************************************************************************
			LOCAL VARIABLES		
*******************************************************************************/

/*******************************************************************************
			LOCAL FUNCTIONS		
*******************************************************************************/

static int exp_mod_init(void);
static void exp_mod_exit(void);

void si_print(int num);
void add_two_num(int a, int b);

/**********************************************************************************************
function	 : exp_mod_init
description	 : This function is initialised when module gets inserted.
		   This function is passed as an argument to module_init.
input param      : NONE
output param     : NONE
**********************************************************************************************/
static int exp_mod_init(void) {
    printk(KERN_INFO "In moduleExp:exporting functions and varible for others\n");
    return 0;
}

/**********************************************************************************************
function	 : exp_mod_exit
description	 : This function is initialised when module gets removed.
		   This function is passed as an argument to module_exit.
input param      : NONE
output param     : NONE
**********************************************************************************************/
static void exp_mod_exit(void) {
    printk("Exit moduleExp....\n"); 
}

/**********************************************************************************************
function	 : si_print()
description	 : This function is initialised when module gets inserted.
		   This function will print "SpanIdea" num of time when called by other module.
input param      : int num
output param     : NONE
**********************************************************************************************/
void si_print(int num) {
 while(num--)  
 printk(KERN_INFO "SpanIdea\n");
}

EXPORT_SYMBOL(si_print);

/**********************************************************************************************
function	 : add_two_num()
description	 : This function is exported function.
		   This function will perform addn and give sum called by other module.
input param      : int a, int b
output param     : NONE
**********************************************************************************************/
void add_two_num(int a, int b) {
	printk(KERN_INFO "Sum of two numbers:%d\n",a+b);   
}

EXPORT_SYMBOL(add_two_num);

module_init(exp_mod_init);
module_exit(exp_mod_exit);

MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);


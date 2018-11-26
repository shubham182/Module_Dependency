/************************************************************************************************
@ileName : dep_mod.c
@author  : Shubham Langde
@teamLead: Rajesh Dommaraju 
@etails  : It is a simple driver dependenyt on exp_mod and will use functions and variables used by it. 
@icense  : SpanIdea Systems Pvt. Ltd. All rights reserved.
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
#define DRIVER_MODULE_DESC			"Dependency Module"
#define DRIVER_MODULE_VERSION			"V1.0"

/*******************************************************************************
			 LOCAL TYPEDEFS		
*******************************************************************************/

/*******************************************************************************
			GLOBAL VARIABLES		
*******************************************************************************/
int gVar;
void si_print(int);
void add_two_num(int,int);

/*******************************************************************************
			LOCAL VARIABLES		
*******************************************************************************/

int num = 3;
int a,b=2;

/*******************************************************************************
			LOCAL FUNCTIONS		
*******************************************************************************/

static int dep_mod_init(void);
static void dep_mod_exit(void);


/**********************************************************************************************
function	 : dep_mod_init
description	 : This function is initialised when module gets inserted.
		   This function is passed as an argument to module_init.
input param      : NONE
output param     : NONE
**********************************************************************************************/
static int dep_mod_init(void) {
    printk(KERN_INFO "In dep_mod: Module is dependent on exp_mod\n");
    si_print(2);
    add_two_num(4,5);
    printk("Value of global variable:%d\n",gVar);
    return 0;
}

/**********************************************************************************************
function	 : dep_mod_exit
description	 : This function is initialised when module gets removed.
		   This function is passed as an argument to module_exit.
input param      : NONE
output param     : NONE
**********************************************************************************************/

static void dep_mod_exit(void) {
    printk("Exit dep_mod...\n"); 
}

module_init(dep_mod_init);
module_exit(dep_mod_exit);

MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);


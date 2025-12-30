#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

/* -------- Module Parameters -------- */

// String parameter
static char *user_name = "DefaultUser";

// Integer parameter
static int user_id = 0;

/*
 * module_param(name, type, permissions)
 * permissions = 0 means not visible in sysfs
 */
module_param(user_name, charp, 0000);
MODULE_PARM_DESC(user_name, "User name passed to the module");

module_param(user_id, int, 0000);
MODULE_PARM_DESC(user_id, "User ID passed to the module");

/* -------- Module Init Function -------- */
static int __init param_module_init(void)
{
    printk(KERN_INFO "User Input Module Loaded\n");
    printk(KERN_INFO "User Name: %s\n", user_name);
    printk(KERN_INFO "User ID: %d\n", user_id);
    return 0;
}

/* -------- Module Exit Function -------- */
static void __exit param_module_exit(void)
{
    printk(KERN_INFO "User Input Module Unloaded. Goodbye %s!\n", user_name);
}

/* -------- Register Functions -------- */
module_init(param_module_init);
module_exit(param_module_exit);

/* -------- Module Info -------- */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Owais Tahir");
MODULE_DESCRIPTION("Parameterized User Input Kernel Module");

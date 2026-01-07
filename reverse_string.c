#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/string.h>

#define MAX_LEN 100

static char *user_name = "DefaultUser";
static char reversed[MAX_LEN];

// Declare string parameter
module_param(user_name, charp, 0000);
MODULE_PARM_DESC(user_name, "User name string parameter");

static int __init reverse_string_init(void)
{
    int len, i;

    len = strlen(user_name);

    if (len >= MAX_LEN)
        len = MAX_LEN - 1;

    // Reverse the string
    for (i = 0; i < len; i++) {
        reversed[i] = user_name[len - i - 1];
    }
    reversed[len] = '\0';

    printk(KERN_INFO "Original string: %s\n", user_name);
    printk(KERN_INFO "Reversed string: %s\n", reversed);

    return 0;
}

static void __exit reverse_string_exit(void)
{
    printk(KERN_INFO "Reverse string module unloaded\n");
}

module_init(reverse_string_init);
module_exit(reverse_string_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Student Name");
MODULE_DESCRIPTION("Kernel module to reverse string parameter");
MODULE_VERSION("1.0");

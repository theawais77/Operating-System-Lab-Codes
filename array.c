#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

#define MAX_NUMS 10   // Maximum number of integers allowed

static int numbers[MAX_NUMS];
static int count = 0;   // How many numbers user passed

// Declare array parameter
module_param_array(numbers, int, &count, 0000);
MODULE_PARM_DESC(numbers, "An array of integers");

static int __init array_param_init(void)
{
    int i;
    int sum = 0;
    int avg = 0;

    printk(KERN_INFO "Module loaded with %d numbers\n", count);

    for (i = 0; i < count; i++) {
        sum += numbers[i];
        printk(KERN_INFO "numbers[%d] = %d\n", i, numbers[i]);
    }

    if (count > 0)
        avg = sum / count;

    printk(KERN_INFO "Sum = %d\n", sum);
    printk(KERN_INFO "Average = %d\n", avg);

    return 0;
}

static void __exit array_param_exit(void)
{
    printk(KERN_INFO "Array parameter module unloaded\n");
}

module_init(array_param_init);
module_exit(array_param_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Student Name");
MODULE_DESCRIPTION("Kernel module using array parameters");
MODULE_VERSION("1.0");

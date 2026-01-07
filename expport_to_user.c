#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define PROC_NAME "module_name_params"

/* Module parameters */
static char *user_name = "DefaultUser";
static int user_id = 0;

module_param(user_name, charp, 0000);
MODULE_PARM_DESC(user_name, "User name parameter");

module_param(user_id, int, 0000);
MODULE_PARM_DESC(user_id, "User ID parameter");

/* Proc read function */
static int proc_show(struct seq_file *m, void *v)
{
    seq_printf(m, "user_name: %s\n", user_name);
    seq_printf(m, "user_id: %d\n", user_id);
    return 0;
}

/* Proc open function */
static int proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, proc_show, NULL);
}

/* Proc file operations */
static const struct proc_ops proc_file_ops = {
    .proc_open    = proc_open,
    .proc_read    = seq_read,
    .proc_lseek   = seq_lseek,
    .proc_release = single_release,
};

/* Module init */
static int __init proc_module_init(void)
{
    proc_create(PROC_NAME, 0, NULL, &proc_file_ops);
    printk(KERN_INFO "Proc module loaded\n");
    return 0;
}

/* Module exit */
static void __exit proc_module_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "Proc module unloaded\n");
}

module_init(proc_module_init);
module_exit(proc_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Student Name");
MODULE_DESCRIPTION("Kernel module exporting parameters via /proc");
MODULE_VERSION("1.0");

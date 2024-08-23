#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/timer.h>


int hallsensor_probe(struct platform_device *pdev){
    return 0;
}
int hallsensor_remove(struct platform_device *pdev)
{
    pr_info("Good bye device tree\n");
    return 0;
}

static int hallsensor_open(struct inode *inode, struct file *file);
static ssize_t hallsensor_read(struct file *file, char __user *buf, size_t count, loff_t *offset);
static ssize_t hallsensor_write(struct file *file, const char __user *buf, size_t count, loff_t *offset);

// static int hallsensor_release(struct inode *inode, struct file *file);
// static long hallsensor_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static const struct file_operations hallsensor_fops = {
    .owner      = THIS_MODULE,
    .open       = hallsensor_open,
    .read       = hallsensor_read,
    .write       = hallsensor_write
    // .release    = hallsensor_release,
    // .unlocked_ioctl = hallsensor_ioctl,
};

static int hallsensor_open(struct inode *inode, struct file *file){
    return 0;
}

static ssize_t hallsensor_read(struct file *file, char __user *buf, size_t count, loff_t *offset){
    return 0;
}

static ssize_t hallsensor_write(struct file *file, const char __user *buf, size_t count, loff_t *offset){
    return 0;
}
static const struct of_device_id hallsensor_of_match[] = {
    {.compatible = "hallsensor"},
    {},
};

static struct platform_driver hallsensor_driver = {
    .probe = hallsensor_probe,
    .remove = hallsensor_remove,
    .driver = {
        .name = "hallsensor",
        .of_match_table = hallsensor_of_match,
    },
};


module_platform_driver(hallsensor_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("TuNa");
MODULE_DESCRIPTION("Hall Sensor Driver");
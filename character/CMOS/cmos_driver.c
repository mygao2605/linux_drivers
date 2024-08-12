#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

static dev_t cmos_dev_number; /* Allotted device number */
struct class *cmos_class; /* Tie with the device model */
#define NUM_CMOS_BANKS 2
#define CMOS_BANK_SIZE (0xFF*8)
#define DEVICE_NAME "cmos"
#define CMOS_BANK0_INDEX_PORT 0x70
#define CMOS_BANK0_DATA_PORT 0x71
#define CMOS_BANK1_INDEX_PORT 0x72
#define CMOS_BANK1_DATA_PORT 0x73
unsigned char addrports[NUM_CMOS_BANKS] = {CMOS_BANK0_INDEX_PORT,CMOS_BANK1_INDEX_PORT,};
unsigned char dataports[NUM_CMOS_BANKS] = {CMOS_BANK0_DATA_PORT,CMOS_BANK1_DATA_PORT,};

struct cmos_dev
{
    unsigned short current_pointer; /* Current pointer within the
    unsigned int size; /* Size of the bank */
    int bank_number; /* CMOS bank number */
    struct cdev cdev; /* The cdev structure */
    char name[10]; 
} *cmos_devp; 



/* File operations structure. Defined in linux/fs.h */
static struct file_operations cmos_fops = {
    .owner = THIS_MODULE, /* Owner */
    .open = cmos_open, /* Open method */
    .release = cmos_release, /* Release method */
    .read = cmos_read, /* Read method */
    .write = cmos_write, /* Write method */
    .llseek = cmos_llseek, /* Seek method */
    .ioctl = cmos_ioctl, /* Ioctl method */
};

int cmos_open(struct inode *inode, struct file *file){

}
int cmos_release(struct inode *inode, struct file *file){

}
ssize_t cmos_read(struct file *file, char *buf, size_t count, loff_t *ppos){

}
ssize_t cmos_write(struct file *file, const char *buf,size_t count, loff_t *ppos){

}

static loff_t cmos_llseek(struct file *file, loff_t offset,int orig){

}
static int cmos_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg){

}

int __init cmos_init(void){

}
void __exit cmos_cleanup(void){

}



module_init(cmos_init);
module_exit(cmos_cleanup);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("TuNa");
MODULE_DESCRIPTION("CMOS driver");
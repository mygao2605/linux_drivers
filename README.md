# linux_drivers
# 1. Character Drivers:
Character devices are those that perform data transfers as a stream of bytes. Each of these files represents a character device:
    - mem: Represents physical memory devices.
    - pty: Represents pseudo-terminal devices, used for terminal emulation.
    - ttyp: Represents a pseudo-terminal slave device, which is part of the terminal emulation system.
    - ttys: Represents serial terminals, such as those connected through serial ports.
    - lp: Represents line printers.
    - vsc: Typically refers to virtual console devices.
    - misc: A catch-all for miscellaneous character devices.
    - input: Represents input devices like keyboards and mice.
    - sound: Represents sound devices.
    - sg: Represents SCSI generic devices.
    - usb: Represents USB devices.

# 2. Block Devices:
Block devices manage data in blocks rather than bytes. They usually represent storage devices
    - fd: Represents floppy disk drives.
    - sd: Represents SCSI disk drives (including SATA and USB disks).
    - sr: Represents CD-ROM or DVD drives.

# 3. Major and Minor number
# 4. Open and Release funtion
+ Open function: int open(struct inode *inode, struct file *file)
    In most drivers, open should perform the following tasks:
    - Check for device-specific errors(such as device not ready or similar hardware problems)
    - Initialize the device if it is being opened for the first time
    - Update the f_op pointer, if necessary
    - Allocate and fill any structure to be put in filp->private_data (Cap phat)
+ Release function: int release(struct inode *inode, struct file *file)
The role of the release method is the reverse of open, Sometime you'll find that the method implementation is called device_close instead of device_release.The device method should perform the following tasks: 
    - Deallocate anything that open allocated in filp->private_data (Giai phong)
    - Shut down the device on last close
# 5. Read and Write function
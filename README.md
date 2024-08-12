# linux_drivers
1. Character Drivers:
Character devices are those that perform data transfers as a stream of bytes. Each of these files represents a character device:

    mem: Represents physical memory devices.
    pty: Represents pseudo-terminal devices, used for terminal emulation.
    ttyp: Represents a pseudo-terminal slave device, which is part of the terminal emulation system.
    ttys: Represents serial terminals, such as those connected through serial ports.
    lp: Represents line printers.
    vsc: Typically refers to virtual console devices.
    misc: A catch-all for miscellaneous character devices.
    input: Represents input devices like keyboards and mice.
    sound: Represents sound devices.
    sg: Represents SCSI generic devices.
    usb: Represents USB devices.

2. Block Devices:
Block devices manage data in blocks rather than bytes. They usually represent storage devices

    fd: Represents floppy disk drives.
    sd: Represents SCSI disk drives (including SATA and USB disks).
    sr: Represents CD-ROM or DVD drives.
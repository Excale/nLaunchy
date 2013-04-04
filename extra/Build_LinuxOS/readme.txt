Linux packager
==============

This makes a phoenix.bin containing everything needed to boot Linux. The
file produced can be fed into the buildos.sh or buildos.bat script to produce a
OS upgrade file that can be used to boot Linux directly from boot2.

Building
--------

First run a `make clean` to clean the directory.

Then run `make KERNEL=/path/to/zImage INITRD=/path/to/initrd CMDLINE="cmdline"`
to build the package. The INITRD option is optional. There's also a
`RAMDISK_SIZE` option for specifying the default ramdisk size in bytes.

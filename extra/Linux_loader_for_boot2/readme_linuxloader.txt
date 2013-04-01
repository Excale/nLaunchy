===================================
| Nspire Linux Loader 2 for Boot2 |
===================================

Usage
=====
nll_classic.tns and nll_cx.tns are actually OS upgrades, which you can use with
nLaunch. Rename the one you need to phoenix.tns, and use the OS update
procedure in nLaunch's readme.

NOTES:
* this loader DOES NOT support input from the keyboard;
* you must use a script file named "linux.ll2.tns" and placed in /documents/linux/.
  There is an exemple of such a script in this folder.
* if you have a Touchpad Nspire, you MUST set the model id in the script file
  before booting the kernel: "mach 4442".
* if you have a CX, you mustn't set the model id or the available memory (no strtol).


How to compile a working Nspire Linux Loader
============================================
1) Get Nspire Linux Loader 2 sources: https://github.com/tangrs/nspire-linux-loader2
2) Replace all #include <os.h> by #include "os.h" and remove all #include <nspireio.h>
3) Add os.h and os.c
4) Set the model at the begining of os.h
5) Replace makefile and add ldscript
6) Hex edit the three hard coded adresses at the very end of the binary file
7) Use buildos to build an OS
8) Use the OS with the latest version of "nLaunch"
9) Have fun


Note to the author of Nspire Linux Loader
=========================================
Could you please integrate this to the trunk of Nspire Linux Loader?
(maybe with a "boot2.h")
Out of tree patches such as this one may get outdated too easily otherwise.
Thanks in advance!
The modifications are placed under the same license as the original Nspire Linux Loader.

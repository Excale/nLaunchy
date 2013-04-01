==============================
|    BuildOS/ BuildImg v2.0  |
==============================

BuildOS and BuildImg help you build TI-Nspire Clickpad, Touchpad and CX OS
update files from the compressed file system and the raw OS code.
They're useful if you know how to make the boot2 accept OS update files...

/!\ Those generated OSes are not valid OSes! In order to be able to launch
them, you need to use a tool such as nLaunch.


What you need
=============
- The raw OS code from a TI OS (use imgmanip: http://ti-pla.net/a4281) or
  your own raw OS code (Linux Loader for boot2, DummyOS, ...)
- The PK-zipped file system from a TI OS or your own PK-zipped file system
  (use deflate algorithm)
  If you don't need any, use an empty zip file
  /!\ If you want to modify the filesystem in recent OSes, you may need to
  repair the zip (among others which were tested, WinRAR gave the best results)
- Windows: 7-Zip (Download the "7-Zip Command Line Version" at
  http://www.7-zip.org/download.html and copy 7za.exe in the current directory)
  *nix: zip


Source code
===========
You can find the source code alongside nLaunch's source code in ../../src .


How to use BuildOS
==================
1) Compile BuildImg and copy buildimg.exe, buildos.bat, buildos.sh and
   header.raw in the current directory
2) Launch buildos.bat / buildos.sh and give what it asks for. It should be
   straightforward. (BuildOS will automatically call BuildImg)
   /!\ BuildOS does not check for all errors. Check by yourself in the console
3) Enjoy!


How to make your own .tnc/batch
===============================
1) Use BuildImg to build the TI-Nspire.img from the PK-zipped OS code (the file
   in the zip should should be named "phoenix.raw") and the PK-zipped file
   system (use deflate algorithm)
2) Rename to TI-Nspire.img, zip the output (do not deflate/compress!)
3) Use any hex-editor to add the content of header.raw at the beginning
4) Rename to .tnc/.tno
5) Enjoy!

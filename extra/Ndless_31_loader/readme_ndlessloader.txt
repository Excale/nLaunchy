==============================
| Modified ndless 3.1 loader |
==============================

This ndless loader is embedded and used in nLaunch as ndless.c
ndless31_loader[] is the compiled ndlessloader.c
ndless31_loader_specific[] are the adresses used for each OS (3.1 CAS and
non-CAS)

Changes needed to compile a working ndless_resource.tns are in install.c.


Note to the author(s) of Ndless
===============================
Could you please integrate this to the main branch of Ndless?
This ndlessloader also gives "L" as parameter so you can easily recognize it.
Out of tree patches such as this one may get outdated too easily otherwise.
Thanks in advance!
The modifications are placed under the same license as ndlessloader.

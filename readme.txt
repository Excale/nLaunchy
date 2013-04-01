=======================
|    nLaunchy v2.1    |
=======================
PLEASE READ THE WHOLE README BEFORE DOING ANYTHING.

nLaunchy is a set of programs and crafted OS updates suitable for:
* Nspire Clickpad and Touchpad calculators running boot2 1.4.1571 ("1.4");
* Nspire CX calculators running boot2 3.1.0.16 ("3.1").
It enables users to install and launch arbitrary OS updates located into the
user-accessible part of the filesystem - especially Linux :-) (see
http://github.com/tangrs/linux for more information )

As usual, use at your own risk :-P

NOTE: I have forked nLaunch CX so that everyone can contribute. I'll add it
to nLaunchy so we can keep one version with all the latest updates/added things
without having to change the name every time :).


Initial installation
====================
Needless to say, all steps are important ;-)

***** Clickpad and Touchpad installation (see below for CX) *****
-----------------------------------------------------------------
0) backup your documents from your nspire on your computer
1) install the 1.4.1571 boot2, usually known as "1.4". See
   http://ti-pla.net/a10080  (easiest way to do it)
   http://ti-pla.net/a3503   (use only if you cannot use the first one)
   http://ti-pla.net/a3507   (use only if you cannot use the first one)
2) get a compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire
   - NOTE: Not all TI-OSes are compatible with nLaunchy.
     OSes 3.1.0.392, 3.2.0.1212, 3.2.0.1219 and 3.2.3.1233 are.
     For a full list of compatible OSes, check src/patch.c
3) use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2
   (you can remove the examples too)
4) rename the TNOC'ed OS to phoenix.tns
5) get to the CLASSIC folder
6) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system
7) if you have installed it on OS 3.1.0.392, uninstall Ndless by launching
   ndless_resources.tns
8) reboot, go to the maintenance menu ( http://ti-pla.net/t5360 ), delete OS
   (option 2)
9) reboot, transfer nlaunch.tno/tnc to your calculator (an error will certainly
   be shown on the computer, check if it is ok on your calculator)
   - /!\ first boot can be fairly long (max 3 min); the progression bar can be
     quite unstable. If the bar did not move at all during 3 minutes, consider
     the boot as a failure
   - NOTE: unplugging the USB cable "at the right time", i.e. after sending
     the TNO/TNC and shortly after the bar has reached 60% again, may increase
     the reliability of the installation procedure. Likewise, the second
     generation of Ndless (1.7/2.0) worked better when USB was unplugged.
10)enjoy :-)
   NOTE: if it is working fine and you want nLaunchy to be more stealthy when
   booting, you can compile a quiet version ("DEBUG 1" in nlaunch.c).


**** CX installation (see above for Clickpad and Touchpad) *****
----------------------------------------------------------------
0) backup your documents from your nspire on your computer
1) install the 3.1.0.16 boot2, usually known as "3.1".
   If you have installed OS 3.1.0.392, 3.2.0.1212, 3.2.0.1219 or 3.2.3.1233 you
   already have it. If you have installed any newer version, you probably will
   not be able to easily install the 3.1.0.16 boot2.
   Otherwise, install OS 3.1.0.392:
   CX CAS: http://ti-pla.net/a3718
   CX    : http://ti-pla.net/a3717
2) get a compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire
   - NOTE: Not all TI-OSes are compatible with nLaunchy.
     OSes 3.1.0.392, 3.2.0.1212, 3.2.0.1219 and 3.2.3.1233 are.
     For a full list of compatible OSes, check src/patch.c
3) use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2
   (you can remove the examples too)
4) rename the TNOC'ed OS to phoenix.tns
5) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system
6) get to the CX folder
7) transfer nlaunch.tns and preloader.tns to your calculator in the folder
   /nlaunch/, being at the root of the user-accessible part of the file-system
8) if you have installed it on OS 3.1.0.392, uninstall Ndless by launching
   ndless_resources.tns
9) reboot (the reset button is the easiest way), go to the maintenance menu
   ( http://ti-pla.net/t5360 ), delete OS (option 2)
10)reboot, transfer nlaunch.tco/tcc to your calculator (an error will certainly
   be shown on the computer, check if it is ok on your calculator)
   - /!\ the initial exploit can fail. If the progress bar is stuck at 60% and
     nothing is shown (you should briefly see "YZ") at the top left of the
     screen, reset and send nlaunch.tco/tcc again.
   - /!\ getting to the OS the first time can be fairly long (max 3 min); the
     progression bar can be quite unstable. If the bar did not move at all
     during 3 minutes, consider the boot as a failure
   - NOTE: unplugging the USB cable "at the right time", i.e. after sending
     the TNO/TNC and shortly after the bar has reached 60% again, may increase
     the reliability of the installation procedure. Likewise, the second
     generation of Ndless (1.7/2.0) worked better when USB was unplugged.
11)enjoy :-)
   - /!\ when rebooting, the progress bar can sometimes be stuck a 60% with
     nothing shown at the top left of the screen. Simply press "reset" until it
     works.
   NOTE: if it is working fine and you want nLaunchy to be more stealthy when
   booting, you can compile a quiet version ("DEBUG 1" in nlaunch.c).


Update of the target OS version
===============================
1) get a compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire
2) Use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2
3) rename the TNOC'ed OS to phoenix.tns
4) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system
5) reboot
   - /!\ first boot can be fairly long (max 3 min); the progression bar can be
     quite unstable.
6) the old OS can now be found in nlaunch/phoenix.old.tns


Update of nLaunchy
==================
1) get to the CLASSIC or CX folder according to your calculator
2) transfer nlaunch.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system.
3) reboot


Uninstallation
==============
1) get any compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire
2) use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2
3) reboot, go to the maintenance menu ( http://ti-pla.net/t5360 ), delete OS
4) reboot, transfer the OS to your calculator


Troubleshooting
===============
Signification of a few debug strings:
* 'U': the OS was not recognized and thus not patched
* 'F': if this is an OS made by TI, this means it was not loaded correctly in
   memory.
CX: if the reset button doesn't work, use a screwdriver to open the battery
door and remove the battery before plugging it back in.


Using Ndless with nLaunch
=========================
* Ndless 1.7/2.0 should work out of the box.
* if you want to use Ndless 3.1 with nLaunch, just send the custom
  ndless_resources.tns provided in this distribution to the /ndless folder,
  then reboot. The Ndless 3.1 loader is embedded in nLaunch.
  If you want to uninstall a Ndless 3.1 handled by nLaunch, just remove
  ndless_resources.tns and reboot. Warning, this is _very_ different from
  vanilla Ndless: vanila Ndless is removed through launching
  ndless_resources.tns, but one mustn't remove ndless_resources.tns !


License
=======

Copyright (C) 2012-2013 nLaunch team
Copyright (C) 2013 nLaunch CX guy
Copyright (C) 2013 Excale

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License version 2, as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.


Contact
=======
Same as nLaunch 1.0: if you have problems or want to submit an idea / a patch,
leave a message on one of the well-known websites of the TI-community.


Changelog
=========

2013-04-01: v2.1: Forked nLaunch CX to nLaunchy and added the "switcher" feature
2013-04-01: v2.0: CX support, by "nLaunch CX guy"
2013-01-01: v1.0: First public version, by "nLaunch team"

Greetings
=========

Everyone who tries to push the envelope and get the most out of their platforms.

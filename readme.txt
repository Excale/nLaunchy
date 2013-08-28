=======================
|    nLaunchy v2.2b   |
=======================
PLEASE READ THE WHOLE README BEFORE DOING ANYTHING.

nLaunchy is a set of programs and crafted OS updates suitable for:
* Nspire Clickpad and Touchpad calculators running boot2 1.4.1571 ("1.4");
* Nspire CX calculators running boot2 3.1.0.16 ("3.1").
It enables users to install and launch arbitrary OS updates located into the
user-accessible part of the filesystem - especially Linux :-) (see
http://github.com/tangrs/linux for more information )

As usual, use at your own risk :-P

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

5) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

6) On the computer, browse to the CLASSIC folder

7) transfer nlaunch.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

8) reboot, go to the maintenance menu ( http://ti-pla.net/t5360 ), delete OS
   (option 2)

9) reboot, transfer nlaunch.tno/tnc to your calculator (an error will certainly
   be shown on the computer, check if it is ok on your calculator)
   - /!\ first boot can be fairly long (max 3 min); the progression bar can be
     quite unstable. If the bar did not move at all during 3 minutes, consider
     the boot as a failure
   - NOTE: unplugging the USB cable "at the right time", i.e. after sending
     the TNO/TNC and shortly after the bar has reached 60% again, may increase
     the reliability of the installation procedure.

10) enjoy :-)


**** CX installation (see above for Clickpad and Touchpad) *****
----------------------------------------------------------------
0) backup your documents from your nspire on your computer

1) install the 3.1.0.16 boot2, usually known as "3.1".
   If you currently have OS 3.1.0.392, 3.2.0.1212, 3.2.0.1219 or 3.2.3.1233 you
   already have it. If you have installed any newer version without TNOC-ing it,
   you probably will not be able to easily install the 3.1.0.16 boot2.
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

6) On the computer, browse to the CX folder

7) transfer nlaunch.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

8) reboot (the reset button is the easiest way), go to the maintenance menu
   ( http://ti-pla.net/t5360 ), delete OS (option 2)

9) reboot, transfer nlaunch.tco/tcc to your calculator (an error will certainly
   be shown on the computer, check if it is ok on your calculator)
   - /!\ the initial exploit can fail. If the progress bar is stuck at 60% and
     nothing is shown (you should briefly see "YZ") at the top left of the
     screen, reset and send nlaunch.tco/tcc again.
   - /!\ getting to the OS the first time can be fairly long (max 3 min); the
     progression bar can be quite unstable. If the bar did not move at all
     during 3 minutes, consider the boot as a failure
   - NOTE: unplugging the USB cable "at the right time", i.e. after sending
     the TCO/TCC and shortly after the bar has reached 60% again, may increase
     the reliability of the installation procedure. Likewise, the second
     generation of Ndless (1.7/2.0) worked better when USB was unplugged.

10) enjoy :-)
   - /!\ when rebooting, the progress bar can sometimes be stuck a 60% with
     nothing shown at the top left of the screen. Simply press "reset" until it
     works.


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

Additional features
===================
* Pressing ESC will trigger the "Download mode", allowing you to transfer
  documents to your Nspire via USB. Reset you Nspire to quit
  /!\ This feature is broken on Nspire CX
* Pressing TAB will try to load Linux by loading
  /documents/linux/linuxloader.tns
* If it is working fine and you want nLaunchy to be more stealthy when booting,
  you can compile a quiet version ("DEBUG 1" in nlaunch.h).


Troubleshooting
===============
If you see any letter on the screen (except PP), see the Debug strings section

CX: if the reset button doesn't work, use a screwdriver to open the battery
door and remove the battery before plugging it back in.

Debug strings
=============
Signification of a few debug strings:
* 'D': you are in download mode
* 'F': loading of the OS failed
* 'K': couldn't update the OS. You probably forgot to move out phoenix.old.tns
* 'U': the OS was not recognized and thus not patched


Using Ndless with nLaunch
=========================
* Ndless 1.7/2.0 should work out of the box.
* if you want to use Ndless 3.1 with nLaunch, use the regular ndless 3.1, but
  make sure the revision is r800 or more.


License
=======
Copyright (C) 2012-2013 nLaunch team
Copyright (C) 2013 nLaunch CX guy
Copyright (C) 2013 Excale
Copyright (C) 2013 Lionel Debroux


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
See https://github.com/Excale/nLaunchy


Changelog
=========
2013-04-01: v2.1: Forked nLaunch CX to nLaunchy and added the "switcher" feature
2013-04-01: v2.0: CX support, by "nLaunch CX guy"
2013-01-01: v1.0: First public version, by "nLaunch team"

Greetings
=========
AlexisVieira and flof0 for beta-testing. 
Everyone who tries to push the envelope and get the most out of their platforms.

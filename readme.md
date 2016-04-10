nLaunchy v2.7
=============
PLEASE READ THE WHOLE README BEFORE DOING ANYTHING.

nLaunchy is a set of programs and crafted OS updates suitable for:
* Nspire Clickpad and Touchpad calculators running boot2 1.4.1571 ("1.4");
* Nspire CX calculators running boot2 3.1.0.16 ("3.1").

It enables users to install and launch arbitrary OS updates located into the
user-accessible part of the filesystem - especially Linux :-) (see
http://tiplanet.org/nspire-linux-builds/ for more information )

As usual, use at your own risk :-P


Initial installation
====================
Needless to say, all steps are important ;-)

***** Clickpad and Touchpad installation (see below for CX) *****
-----------------------------------------------------------------
0) backup all your documents from your Nspire on your computer

1) install the 1.4.1571 boot2, usually known as "1.4". See
   http://ti-pla.net/a10080  (easiest way to do it)
   http://ti-pla.net/a3503   (use only if you cannot use the first one)
   http://ti-pla.net/a3507   (use only if you cannot use the first one)

2) get a compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire
   - NOTE: Not all TI-OSes are compatible with nLaunchy (but many are).
     OSes 3.1.0.392, 3.6.0.546 and 3.9.0.46x are.
     For a full list of compatible OSes, check src/patch.c

3) use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2
   (you can remove the examples too)

4) rename the TNOC'ed OS to phoenix.tns

5) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

6) on the computer, browse to the CLASSIC folder

7) transfer nlaunch.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

8) reboot, go to the maintenance menu ( http://ti-pla.net/t5360 ), delete OS
   (option 2 (you might have to press `t` on a touchpad calculator))

9) reboot, transfer nlaunch.tno/tnc to your calculator (an error will certainly
   be shown on the computer, check if it is ok on your calculator)
   - /!\ first boot can be fairly long (max 3 min); the progression bar can be
     quite unstable. If the bar did not move at all during 3 minutes, consider
     the boot as a failure

10) enjoy :-)


**** CX installation (see above for Clickpad and Touchpad) *****
----------------------------------------------------------------
0) backup all your documents from your Nspire on your computer

1) install the 3.1.0.16 boot2, usually known as "3.1".
   - If your current OS is older than 3.1, install OS 3.1.0.392.
   - If your current OS is between 3.1 and 3.2.3, you probably already have it.
   - If your current OS is between 3.3 and 4.2, install OS 4.2 and use
   nsNandMgr ( http://ti-pla.net/a10080 ).
   - If you have installed any newer version without TNOC-ing it, you will
   probably not be able to easily install the 3.1.0.16 boot2

2) get a compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire
   - NOTE: Not all TI-OSes are compatible with nLaunchy (but many are).
     OSes 3.1.0.392, 3.6.0.546, 4.0.3.29 and 4.2.0.532 are.
     For a full list of compatible OSes, check src/patch.c

3) use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2
   (you can remove the examples too)

4) rename the TNOC'ed OS to phoenix.tns

5) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

6) on the computer, browse to the CX folder

7) transfer nlaunch.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

8) reboot (the reset button is the easiest way), go to the maintenance menu
   ( http://ti-pla.net/t5360 ), delete OS (option 2)

9) reboot, transfer nlaunch.tco/tcc to your calculator (an error will certainly
   be shown on the computer, check if it is ok on your calculator)
   - /!\ the initial exploit can fail. If the progress bar is stuck at 60% and
     nothing is shown (you should briefly see "YZ") at the top left of the
     screen, reset and send nlaunch.tco/tcc again
   - /!\ if the screen becomes very bright (white/blue color), reset and try
     again
   - /!\ getting to the OS the first time can be fairly long (max 3 min); the
     progression bar can be quite unstable. If the bar did not move at all
     during 3 minutes, consider the boot as a failure

10) enjoy :-)
   - /!\ when rebooting, the progress bar can sometimes be stuck a 60% with
     nothing shown at the top left of the screen. Simply press "reset" until it
     works


Update of the target OS version
===============================
1) get a compatible OS. See
   http://tiplanet.org/forum/archives_list.php?id=OS+Nspire

2) use TNOC ( http://ti-pla.net/a1922 ) on the OS upgrade to remove the boot2

3) rename the TNOC'ed OS to phoenix.tns

4) transfer phoenix.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

5) reboot
   - /!\ first boot can be fairly long (max 3 min); the progression bar can be
     quite unstable

6) the old OS can now be found in nlaunch/phoenix.old.tns


Update of nLaunchy
==================
1) get to the CLASSIC or CX folder according to your calculator

2) transfer nlaunch.tns to your calculator in the folder /nlaunch/, being at
   the root of the user-accessible part of the file-system

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
The following keys should be pressed at boot time before PP gets printed
and released once 3 gets printed on the screen
* Pressing ESC will trigger the "Download mode", allowing you to transfer
  documents to your Nspire via USB. Reset you Nspire to quit
  /!\ This feature is broken on Nspire CX
* Pressing TAB will try to load Linux by loading
  /documents/linux/linuxloader.tns
* If it is working fine and you want nLaunchy to be more stealthy when booting,
  you can compile a quiet version ("DEBUG 1" in nlaunch.h)
* If compiled with OVERCLOCK=1:
  Will overclock your Nspire under some OSes
* If compiled with MULTIOS=1:
  Pressing the n-th key (counting from 0) of the following list:
  Clickpad: 1U2V3W+, Touchpad/CX: 1STU3VWX will, if the file exists, install
  /documents/nlaunch/phoenix_n.tns and move the current OS in the first
  available spot


Troubleshooting
===============
If you see any letter on the screen (except PP), see the Debug strings section

CX: if the reset button doesn't work, use a screwdriver to open the battery
door and remove the battery before plugging it back in


Debug strings
=============
Signification of a few debug strings:
* 'C': couldn't clean the old resources
* 'D': you are in download mode
* 'F': loading of the OS failed
* 'K': couldn't update the OS. You probably forgot to move out phoenix.old.tns
* 'U': the OS was not recognized and thus not patched


Using Ndless with nLaunch
=========================
* Ndless 1.7/2.0 should work out of the box
* Ndless 3.x/4.x: place the regular ndless_resources.tns file in
  /documents/ndless/, then reboot


License
=======
* Copyright (C) 2012-2013 nLaunch team
* Copyright (C) 2013      nLaunch CX guy
* Copyright (C) 2013-2016 Excale
* Copyright (C) 2013-2015 Lionel Debroux

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
* 2016-04-10: v2.7: Release 2.7 (Ndless 4.2 support)
* 2016-01-15: v2.6: Release 2.6 (Ndless 4.0 support)
* 2015-02-24: v2.5: Release 2.5 (Ndless 3.9 support)
* 2014-03-15: v2.4: Release 2.4 (Ndless 3.6 support)
* 2013-10-25: v2.3: Release 2.3 
* 2013-08-28: v2.2: Release 2.2 
* 2013-04-01: v2.1: Forked nLaunch CX to nLaunchy and added the "switcher"
                    feature
* 2013-04-01: v2.0: CX support, by "nLaunch CX guy"
* 2013-01-01: v1.0: First public version, by "nLaunch team"


Greetings
=========
AlexisVieira, critor, flof0, Legimet and more :)

Everyone who tries to push the envelope and get the most out of their platforms.

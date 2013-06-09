rem nLaunchy
rem
rem Copyright (C) 2012-2013 nLaunch team
rem Copyright (C) 2013-2013 nLaunch CX guy
rem
rem This program is free software; you can redistribute it and/or modify
rem it under the terms of the GNU General Public License version 2, as
rem published by the Free Software Foundation.
rem
rem This program is distributed in the hope that it will be useful,
rem but WITHOUT ANY WARRANTY; without even the implied warranty of
rem MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
rem GNU General Public License for more details.
rem
rem You should have received a copy of the GNU General Public License
rem along with this program; if not, write to the Free Software Foundation,
rem Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
rem

@echo off
cls

echo #####################################################
echo #                  Build OS Batch                   #
echo #####################################################

set /p oscode= Enter raw OS code filename: 
set /p fs= Enter zipped-filesystem filename: 
set /p output= Enter output filename: 

if not exist %oscode% goto fail0
if not exist %fs%     goto fail0

mkdir temp
copy /b %oscode% temp\phoenix.raw
cd temp
..\7za.exe a -tzip -mx5 phoenix.zip phoenix.raw
..\buildimg.exe phoenix.zip ..\%fs% TI-Nspire.img
..\7za.exe a -tzip -mx0 TI-Nspire.zip TI-Nspire.img
cd ..
if not exist temp\TI-Nspire.zip goto fail
if not exist header.raw goto fail1
copy /b header.raw + temp\TI-Nspire.zip %output%
rmdir temp /S /Q
echo #####################################################
echo #                       DONE                        #
echo #####################################################
pause
exit


:fail0
echo Input file does not exist, aborting!
goto fail
:fail1
echo header.raw is missing!
:fail
echo #####################################################
echo #               An error occured!                   #
echo #     Please check above for more informations.     #
echo #####################################################
rmdir temp /S /Q
pause
exit

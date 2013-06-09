#!/bin/sh
#
# nLaunchy
#
# Copyright (C) 2012-2013 nLaunch team
# Copyright (C) 2013 nLaunch CX guy
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2, as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.


echo "#####################################################"
echo "#                  Build OS Batch                   #"
echo "#####################################################"

if [ ! -f header.raw ]
then
    echo "header.raw does not exist, aborting!"
    exit 1
fi

echo "Enter raw OS code filename:"
read oscode
if [ ! -f "$oscode" ]
then
    echo "Input file does not exist, aborting!"
    exit 1
fi

echo "Enter zipped filesystem filename:"
read fs
if [ ! -f "$fs" ]
then
    echo "Input file does not exist, aborting!"
    exit 1
fi

echo "Enter output filename:"
read output
if [ -f "$output" ]
then
    echo "Output file exists, aborting!"
    exit 1;
fi

TEMP=`mktemp -d`
cp "$oscode" "$TEMP/phoenix.raw"
OLD_PWD=$PWD
cd "$TEMP"
7za a -tzip -mx5 phoenix.zip phoenix.raw || exit 1
"$OLD_PWD/buildimg" phoenix.zip "$OLD_PWD/$fs" TI-Nspire.img || exit 1
7za a -tzip -mx0 TI-Nspire.zip TI-Nspire.img || exit 1
cd "$OLD_PWD"
cat header.raw "$TEMP/TI-Nspire.zip" > "$output" || exit 1
rm -Rf "$TEMP"

echo "#####################################################"
echo "#                       DONE                        #"
echo "#####################################################"

#!/bin/bash

# Bash script for installing Arch-Linux to my preferences
# Boot mode is for non UEFI
#
# Current status: BUILDING...

# Check internet connection before anything
# ADD SECTION

# Partition Disks
# Number should be adjusted before script runs (later passed as args)


#parted commands follow
#Put this in a text file and do parted < fillename
mklabel gpt
unit mib
mkpart primary 1 3
name 1 grub
set 1 bios_grub on
mkpart primary 3 131
name 2 boot
mkpart primary 131 643
name 3 swap
mkpart primary 643 -1
name 4 rootfs
set 2 boot on
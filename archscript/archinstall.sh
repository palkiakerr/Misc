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
parted < mklabel gpt
parted < unit mib
parted < mkpart primary 1 3
parted < name 1 grub
parted < set 1 bios_grub on
parted < mkpart primary 3 131
parted < name 2 boot
parted < mkpart primary 131 643
parted < name 3 swap
parted < mkpart primary 643 -1
parted < name 4 rootfs
parted < set 2 boot on

#!/bin/bash

# Bash script for installing Arch-Linux to my preferences
# Boot mode is for non UEFI
#
# Current status: BUILDING...

# Check internet connection before anything
# ADD SECTION

# Partition Disks
# Number should be adjusted before script runs (later passed as args)

# Speeds up download of git
cp /etc/pacman.d/mirrorlist /etc/pacman.d/mirrorlist.backup
sed -i 's/^#Server/Server/' /etc/pacman.d/mirrorlist.backup
rankmirrors -n 6 /etc/pacman.d/mirrorlist.backup > /etc/pacman.d/mirrorlist
pacman -S git
parted < partcommands

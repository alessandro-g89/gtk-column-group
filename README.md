gtk-column-group
================

Module for pcmanfm/libfm to show the group ownership of files and
directories in an additional column.

Requires libfm-gtk-dev for building, e.g. on Debian-based distros use:

	$ sudo apt-get install libfm-gtk-dev

To build and install, use:

	$ make
	$ sudo make install

The module is installed under /usr/lib/x86_64-linux-gnu, which is correct
for multiarch 64-bit installations. For 32-bit installation change LIBDIR
to /usr/lib/i386-linux-gnu in the Makefile. For other architectures
change as appropriate.

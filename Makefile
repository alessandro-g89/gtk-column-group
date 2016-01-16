NAME = gtk-column-group
LIBDIR = /usr/lib/x86_64-linux-gnu
CFLAGS = `pkg-config --cflags libfm gtk+-2.0`
AM_LDFLAGS = -rpath $(LIBDIR)/libfm/modules/ -no-undefined -module -avoid-version 

all:
	libtool --mode=compile gcc $(CFLAGS) -c $(NAME).c
	libtool --mode=link gcc $(AM_LDFLAGS) $(NAME).lo -o $(NAME).la

install:
	libtool --mode=install install -c $(NAME).la $(LIBDIR)/libfm/modules/
	libtool --finish $(LIBDIR)/libfm/modules/

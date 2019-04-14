
OS = LINUX
#OS = MACOSX
#OS = WINDOWS

PROG = rawhid_test

# To set up Ubuntu Linux to cross compile for Windows:
#
#    apt-get install mingw32 mingw32-binutils mingw32-runtime libusb-dev
#
# Just edit the variable above for WINDOWS, then use "make" to build rawhid.exe


TARGET = $(PROG)
CC = gcc
CPP = g++
STRIP = strip
CFLAGS = -Wall -O2 -I../include
CPPFLAGS = -Wall -O2 -I../include
LIBS = -lusb

OBJS = $(PROG).o hid.o


all: $(TARGET)

$(PROG): $(OBJS)
	$(CPP) -o $(PROG) $(OBJS) $(LIBS)
	$(STRIP) $(PROG)

$(PROG).exe: $(PROG)
	cp $(PROG) $(PROG).exe

$(PROG).dmg: $(PROG)
	mkdir tmp
	cp $(PROG) tmp
	hdiutil create -ov -volname "Raw HID Test" -srcfolder tmp $(PROG).dmg

hid.o: hid_LINUX.c ../include/hid.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(PROG) $(PROG).exe $(PROG).dmg
	rm -rf tmp


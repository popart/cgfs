CC = c99
CFLAGS = -Wall -g
INCLUDE = -I /usr/include/cairo
LIBDIR = -L /usr/lib
LIBS = -l cairo

all:
	$(CC) $(CFLAGS) main.c $(INCLUDE) $(LIBDIR) $(LIBS) -o build/out
clean:
	rm build/*

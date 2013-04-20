 
PROG=i2c_echo

CC=gcc
CFLAGS=-O2 -Wall -g -rdynamic -std=c99

i2c_echo:
	$(CC) i2c_echo.c $(CFLAGS) -o $(PROG)

clean:
	rm -f *.o $(PROG)
CC=gcc
CFLAGS=-fno-stack-protector -fpack-struct -I.

rba: rba.o
	$(CC) -o rba rba.o

clean:
	rm -f *.o rba

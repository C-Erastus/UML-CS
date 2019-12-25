CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o bit_flags.o


hello: $(OBJECTS)
	$(CC) $(CFLAGS) -o  bit_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
bit_flags.o: bit_flags.h bit_flags.c
	$(CC) $(CFLAGS) -c bit_flags.c -o bit_flags.o
clean: 
	rm bit_driver $(OBJECTS)

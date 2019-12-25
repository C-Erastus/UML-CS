CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o priority_queue.o


hello: $(OBJECTS)
	$(CC) $(CFLAGS) -o  priority_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
bit_flags.o: priority_queue.h priority_queue.c
	$(CC) $(CFLAGS) -c priority_queue.c -o priority_queue.o
clean: 
	rm priority_driver $(OBJECTS)

CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o linked_queue.o


hello: $(OBJECTS)
	$(CC) $(CFLAGS) -o  queue_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
bit_flags.o: linked_queue.h linked_queue.c
	$(CC) $(CFLAGS) -c linked_queue.c -o linked_queue.o
clean: 
	rm queue_driver $(OBJECTS)

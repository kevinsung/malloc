CC = gcc
CFLAGS = -c -Wall -g

all: test1

test1: test1.c my_malloc.o
	$(CC) -o test1 test1.c my_malloc.o

my_malloc.o: my_malloc.c header.h
	$(CC) $(CFLAGS) my_malloc.c

clean:
	rm -rf *.o test1

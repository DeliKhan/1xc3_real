CC = gcc
CFLAGS = -g -Wextra -Wall

all: main

main: main.o functions.o
	$(CC) $(CFLAGS) -o main main.o functions.o

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f main *.o

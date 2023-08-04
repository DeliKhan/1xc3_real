CC = gcc
CFLAGS = -g
all: main
main: main.o functions.o readFile_randWord.o
	$(CC) $(CFLAGS) -o main main.o functions.o readFile_randWord.o
main.o: main.c constants.h readFile_randWord.h functions.h
	$(CC) -c main.c
functions.o: functions.c functions.h constants.h
	$(CC) -c functions.c
readFile_randWord.o: readFile_randWord.c readFile_randWord.h constants.h
	$(CC) -c readFile_randWord.c
clean:
	rm -f main *.o


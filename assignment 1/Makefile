CC = gcc
CFLAGS = -g -Wextra -Wall -std=c17 -lm
all: ATM_Bank_a ATM_Bank_b ATM_Bank_c#ATM
#ATM: ATM_Bank_a.o ATM_Bank_b.o ATM_Bank_c.o
ATM_Bank_a:
	$(CC) $(CFLAGS) -o ATM_Bank_a ATM_Bank_a.c
ATM_Bank_b:
	$(CC) $(CFLAGS) -o ATM_Bank_b ATM_Bank_b.c -lm
ATM_Bank_c:
	$(CC) $(CFLAGS) -o ATM_Bank_c ATM_Bank_c.c -lm
clean:
	rm -f "*.*"

#So let me explain: This is a modified version specifically to help for the assignment
#Here, we create a variable ATM, which is the output files of the three c programs
#Make is smart enough to realize that you are implying to compile each of those output files first
#Note: since the third program needs -lm, I seperately called it to have its own unique execution
##I could have done this:
##CFLAGS = -Wextra -Wall -std=c17 -lm
##ATM: ATM_Bank_a.o ATM_Bank_b.o ATM_Bank_c.o
#This would have also worked, just that all of them would have lm

#If you want to combine multiple .o files together, do the following
##ATM: ATM_Bank_a.o ATM_Bank_b.o ATM_Bank_c.o
########$(CC) $(CFLAGS) -o ATM ATM_Bank_a.o ATM_Bank_b.o ATM_Bank_c.o

#The clean function will clean anything with a .o, not just the ones I specified, unfortunately
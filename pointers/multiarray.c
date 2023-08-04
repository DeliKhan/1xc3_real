#include <stdio.h>

int main()
{
    // Ragged array of strings
    char *names[] = {"Anne-Marie", "Anna", "Mahmoud", "Kian", "Raouf", "Nikki"};
    // notice you don't need to say the character limit if you use pointer, if you did this traditionally
    //  char names[][12] = {"Anne-Marie", "Anna", "Mahmoud", "Kian", "Raouf", "Nikki"};
    // HOWEVER, NOTE THE DIFFERENCE WHEN YOU PRINT THE CHAR AFTER THE \0
    // For pointer: it continues to the next value(so in this case, for the second, it would print M)
    // In other words: it treats it like a one-dimensional array
    // For the list: it sticks to the same element and prints \0
    //  Accessing and printing the elements and their lengths
    for (int i = 0; i < 6; i++)
    {
        int length = 0;
        while (names[i][length] != '\0')
        {
            length++;
        }
        printf("Name %d: %s (Length: %d) - After '\\0': '%c'\n", i + 1, names[i], length, names[i][length]);
    }
}
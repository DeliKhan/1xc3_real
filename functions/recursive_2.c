#include <stdio.h>
#include <stdlib.h>              // Include this header for atoi and atof
int main(int argc, char *argv[]) // argc tells us how many elements are in argv
{
    // Check the number of inputs
    if (argc != 3)
    {
        printf(" Incorrect number of inputs . Expected 2 inputs .\n");
        return 1; // Exit the program with an error status
    }
    // Retrieve the input arguments
    int arg1 = atoi(argv[1]);   // Convert the first argument to an integer
    float arg2 = atof(argv[2]); // Convert the second argument to a float
    // Use the input arguments
    printf(" First argument : %d\n", arg1);
    printf(" Second argument : %.2f\n", arg2);
    return 0; // Exit the program with a success status
}
// argc is not something you type, it calculates how many inputs you gave by splitting by spaces
// so if I gave "./recursive_2 2 3.0", argc=3
// argv holds each of the inputs you gave (so argv[0] = "./recursive_2")
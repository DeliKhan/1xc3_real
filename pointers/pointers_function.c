#include <stdio.h>
void printNumber(int *ptr)
{
    // Using a pointer to modify the value passed to the function
    *ptr = 10;
    printf(" Number inside the function : %d\n", *ptr);
}
int main()
{
    int number = 5; // Variable declared inside the main function
    printf(" Number inside the main function : %d\n", number);
    // Pass the address of ’number ’ to the function
    printNumber(&number);
    // The value of ’number ’ has been modified by the function
    printf(" Number after the function call : %d\n", number);
}
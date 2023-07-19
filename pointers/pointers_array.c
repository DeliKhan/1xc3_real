#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50}; // Initializing an array with values
    // Printing the address and value of each element in the array
    for (int i = 0; i < 5; i++)
    {
        printf("arr [%d] = %d with address %p\n", i, arr[i], (arr + i)); //&arr[i]); Both mean the same thing
        // so &p and p both give memory addresses if p is a pointer
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void allocateOnStack(const int size)
{
    int largeArray[size]; // Attempt to allocate the array on the stack
    printf(" Stack memory allocation Succeed !\n");
}
void allocateOnHeap(const int size)
{
    int *largeArray = (int *)malloc(size * sizeof(int)); // Allocate the array on the heap
    // Check if memory allocation is successful
    if (largeArray != NULL)
    {
        printf(" Heap memory allocation Succeed !\n\n");
        free(largeArray);
    }
    else
    {
        printf(" Memory allocation failed !\n\n");
    }
}
int main()
{
    // run this to see how much size each ‘int ‘ takes in yourmachine
    // mine Size of int: 4 bytes
    printf(" Size of int : %zu bytes \n", sizeof(int));
    // so the maximum number of integers I can Save on stack is:
    // 8192 * 1024 / 4 = 2 ,097 ,152
    // this show the maximum integer value I can save by type ‘int ‘
    printf(" Maximum value of int: %d\n\n", INT_MAX);
    int SIZE = 2098100;
    printf(" Attempting to allocate on heap ...\n");
    allocateOnHeap(SIZE); // This will successfully allocate memory on the heap
    printf(" Attempting to allocate on stack ...\n");
    allocateOnStack(SIZE); // This will cause a stack overflow
}
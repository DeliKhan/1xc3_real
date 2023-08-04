#include <stdio.h>

void printArrayElements(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: Value = %d, Address = %p\n", i, arr[i], &arr[i]);
    }
}

int main()
{
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Array elements in main function:\n");
    printArrayElements(array, size);
}
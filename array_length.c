#include <stdio.h>
#include <stdlib.h>

int main()
{
    char array1[3];
    char array2[5] = {'a', 'b', 'c', 'd', 'e'};
    int array3[5] = {1, 2, 3, 4, 5};
    printf("Length of an item in array1: %d\n", sizeof(array1[0]));
    printf("Length of array1: %d\n", sizeof(array1));
    printf("Length of an item in array2: %d\n", sizeof(array2[0]));
    printf("Length of array2: %d\n", sizeof(array2));
    printf("Length of an item in array3: %d\n", sizeof(array3[0]));
    printf("Length of array3: %d\n", sizeof(array3));
    printf("Estimated Length of array3: %d\n", 5 * sizeof(int));
    printf("Last element of array3: %c\n", array2[5]);
}
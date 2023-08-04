#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf(" Enter the number of elements : ");
    scanf("%d", &n);
    // Allocate memory for an array of integers
    int *arr = malloc(n * sizeof(int));
    // Check for allocation failure
    if (arr == NULL)
    {
        printf(" Memory allocation failed . Exiting the program .\n");
        return 1;
    }
    // Print the number of elements and the size of each element in bytes
    printf(" Number of elements : %d\n", n);
    printf(" Size of each element : %zu bytes \n", sizeof(*arr));
    // Print the value in the first element ( garbage value , since it’s not initialized )
    printf(" Value in the first element : %d\n", arr[0]);
    // Deallocate memory
    free(arr);
}

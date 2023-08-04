#include <stdio.h>
int *min(int *n1, int *n2)
{
    return (*n1 < *n2) ? n1 : n2;
}
int main()
{
    int num1 = 10;
    int num2 = 5;
    int *result = min(&num1, &num2); // the address of min is being sent to result (that is, the return statement's address)
    printf("The minimum value is: %d\n", *result);
}
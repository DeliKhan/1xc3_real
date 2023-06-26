#include <stdio.h>
int main()
{
    int a = 5;
    int b = 3;
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b; // be careful, C rounds (in this case, down) cause this aint a float
    // interesting, if you change quotient to double/float, you get 1.0000, its doing the operation then converting to double
    int remainder = a % b;
    printf("Sum: %d\n", sum);
    printf(" Difference : %d\n", difference);
    printf(" Product : %d\n", product);
    printf(" Quotient : %d\n", quotient);
    printf(" Remainder : %d\n", remainder);
    return 0;
}
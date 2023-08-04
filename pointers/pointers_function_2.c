#include <stdio.h>

void calculate(double num, double *square, double *cube)
{ // we didn't make num a pointer, cause we aren't trying to change its value anyway, so not worth it
    // but we could save some memory...

    // update the value stored at square pointer
    *square = num * num;

    // update the value stored at cube pointer
    *cube = num * num * num;
}

int main()
{
    // Initial value
    double number = 5.0;

    // Variables to store the results
    double result_square, result_cube;

    // Call the function to calculate the square and cube
    calculate(number, &result_square, &result_cube);

    // Print the results
    printf("Number: %.2f\n", number);
    printf("Square: %.2f\n", result_square);
    printf("Cube: %.2f\n", result_cube);
}
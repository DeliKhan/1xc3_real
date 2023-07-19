#include <stdio.h>
int main()
{
    int variable1 = 10;
    double variable2 = 3.14;
    const int const1 = 20;
    const double const2 = 2.71;
    int *variable_pointer_to_variable = &variable1;
    int *const const_pointer_to_variable = &variable2;
    const int *variable_pointer_to_const = &const1;
    const int *const const_pointer_to_const = &const2;
    // Allowed : var is not const , so can be changed .
    variable1 = 12;
    // Not Allowed : con is const , so cannot be changed .
    const1 = 30;
    // Allowed : pointer itself is not const , so can be changed .
    variable_pointer_to_variable = &variable2;
    // Allowed : variable pointed to is not const , so can be changed .
    *variable_pointer_to_variable = 30;
    // Not Allowed : pointer itself is const , so cannot be changed .
    const_pointer_to_variable = &variable1;
    // Allowed : variable pointed to is not const , so can be changed .
    *const_pointer_to_variable = 30;
    // Allowed : pointer itself is not const , so can be changed
    variable_pointer_to_const = &const2;
    // Not Allowed : variable pointed to is const , so cannot bechanged.
    *variable_pointer_to_const = 50;
    // Not Allowed : pointer itself is const , so cannot be changed .
    const_pointer_to_const = &const1;
    // Not Allowed : variable pointed to is const , so cannot be changed.
    *const_pointer_to_const = 30;
}

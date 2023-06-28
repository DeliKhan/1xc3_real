#include <stdio.h>
int main()
{
    const double Ped = 1.23456789;
    // Printing options with different placeholders
    // Minimum width = 0 , 2 digits after decimal
    printf(" Printing options for Ped = %.2f:\n", Ped);
    // Minimum width = 10 , 4 digits after decimal
    printf(" Printing options for Ped = %10.4f:\n", Ped);
    // Minimum width = 6 , 8 digits after decimal
    printf(" Printing options for Ped = %6.8f:\n", Ped);
}
/* TLDR:
    The digits before the . represent minimum width,
    if digits before . > digits after . --> you get empty spaces in front
    if digits before .< digits after . --> you get a normal print
    */
#include <stdio.h>
int main()
{
    int a = 42; // Declare and initialize an integer variable
    int *p;     // Declare a pointer to an integer
    /* NOTE: IF YOU WANT TO ASSIGN a to p at start, do int *p = &a, but if you want to modify address, do p = &a*/
    p = &a; // Assign the address of ’a’ to the pointer ’p’
    /* or we could use int *p = &a;*/
    printf(" Value of ’a ’: %d\n", a);
    printf(" Address of ’a ’: %p\n", &a); // %p is placeholder
    printf(" Value of ’p’ ( address of ’a ’): %p\n", p);
    printf(" Value pointed by ’p ’: %d\n", *p); // De - reference p
    *p = 500;
    printf("\nPrint out after *p =500.\n");
    printf(" Value of ’a ’: %d\n", a);
    printf(" Value pointed by ’p ’: %d\n", *p);
    a = 98;
    printf("\nPrint out after a = 98.\n");
    printf(" Value of ’a ’: %d\n", a);
    printf(" Value pointed by ’p ’: %d\n", *p);
}
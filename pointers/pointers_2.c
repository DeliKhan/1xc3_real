#include <stdio.h>
int main()
{
    int a, b, *p1, *p2;
    printf("The initial values :\n");
    printf("a=%d\n", a);
    printf("b=%d\n", b);
    printf("The address of a is: %p\n", &a);
    printf("The address of b is: %p\n", &b);
    printf("The address p1 is: %p\n", p1);
    printf("The address p2 is: %p\n", p2);
    printf("\n");
    p1 = &a;
    p2 = p1; // NOTE: FOR POINTERS to get their address, you don't need &, & is only for non-pointers
    printf(" Result after p1 = &a and p2 = p1 :\n");
    printf(" Value of *p1: %d\n", *p1);
    printf(" Value of *p2: %d\n", *p2);
    printf(" Value of a: %d\n", a);
    printf("The address p1 is: %p\n", p1);
    printf("The address p2 is: %p\n", p2);
    printf("\n");
    *p1 = 1;
    printf(" Step 1, after *p1 = 1:\n");
    printf(" Value of *p1: %d\n", *p1);
    printf(" Value of *p2: %d\n", *p2);
    printf(" Value of a: %d\n", a);
    printf("The address p1 is: %p\n", p1);
    printf("The address p2 is: %p\n", p2);
    printf("\n");
    *p2 = 2;
    printf(" Step 2, after *p2 = 2;\n");
    printf(" Value of *p1: %d\n", *p1); // Output : 2
    printf(" Value of *p2: %d\n", *p2); // Output : 2
    printf(" Value of a: %d\n", a);     // Output : 2
    printf("The address p1 is: %p\n", p1);
    printf("The address p2 is: %p\n", p2);
}

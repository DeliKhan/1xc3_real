#include <stdio.h>
int main()
{
    int x = 10, y = 20, *p1, *p2;
    p1 = &x;
    p2 = &y;
    printf("The initial values :\n");
    printf("a=%d\n", x);
    printf("b=%d\n", y);
    printf("The address of x is: %p\n", &x);
    printf("The address of y is: %p\n", &y);
    printf("The address p1 is: %p\n", p1);
    printf("The address p2 is: %p\n", p2);
    printf("\n");
    *p1 = *p2;
    printf(" After *p1 = *p2 :\n");
    printf("a=%d\n", x);
    printf("b=%d\n", y);
    printf(" Value at address pointed by p1: %d\n", *p1);
    printf(" Value at address pointed by p2: %d\n", *p2);
    printf("The address of x is: %p\n", &x);
    printf("The address of y is: %p\n", &y);
    printf("The address p1: %p\n", p1);
    printf("The address p2: %p\n", p2);

    *p1 /= 2;
    printf(" Now I have modified p1, see what happens to p2\n");
    printf(" Value at p1=%d\n", *p1);
    printf(" Value at p2=%d\n", *p2);
}
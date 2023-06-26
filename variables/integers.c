#include <stdio.h>
int main()
{
    int x;
    int y = x + 5; // Using uninitialized variable x
    printf("%d\n", y);
}
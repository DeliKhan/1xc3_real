#include <stdio.h>
int main()
{
    int x = 5;
    int pre = 0;
    int post = 0;
    pre = ++x + 1; // this adds one to x before the line is executed, thus pre = 7
    x = 5;
    post = x++ + 1; // this adds one to x after the line is executed, thus post = 6
    x = 5;
    printf("%d\n", pre);
    printf("%d\n", post);
}

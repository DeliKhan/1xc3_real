#include <stdio.h>
int main()
{
    int rows = 5;
    int columns = 3;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            printf("(%d, %d) ", i, j);
        }
        printf("\n");
    }
}
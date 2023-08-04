#include <stdio.h>

int main()
{

    int x = 0;
    int y = 0;

    while (x <= 2)
    {
        while (y <= 2)
        {
            printf("%d ", x + y);
            y += 1;
        }
        printf("\n");
        y = 0;
        x += 1;
    }
    return 0;
}
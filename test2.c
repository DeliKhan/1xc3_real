#include <stdio.h>

int main()
{
    int x = 5;
    int y = 0;

    while (x < 20)
    {
        while (y < 10)
        {
            printf("%d ", x);
            printf("%d\n", y);
            y += 1;
        }
        y = 0;
        x += 2;

        if ((x + y) >= 12 && (x + y) % 3 == 0)
        {
            break;
        }
    }

    return 0;
}
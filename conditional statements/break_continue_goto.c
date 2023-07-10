#include <stdio.h>
int main()
{
    int i;
    // Example with break
    for (i = 1; i <= 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        printf("%d ", i);
    }
    printf("\n");
    // Example with continue
    for (i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    // Example with goto
    for (i = 1; i <= 3; i++)
    {
        printf(" Outer loop iteration : %d\n", i);
        for (int j = 1; j <= 3; j++)
        {
            printf(" Inner loop iteration : %d\n", j);
            if (j == 2)
            {
                goto end;
            }
        }
    }
end:
    printf(" Goto example finished .\n");
}
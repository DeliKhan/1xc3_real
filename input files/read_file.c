#include <stdio.h>
int main()
{
    FILE *file = fopen("A.txt", "r");
    if (file == NULL)
    {
        printf(" Error opening the file .\n");
        return 1;
    }
    double number;
    while (fscanf(file, "%lf", &number) == 1)
    {
        printf("%.3lf ", number);
        char ch = fgetc(file); // Read the next character
        if (ch == '\n' || ch == EOF)
        {
            printf("\n");
        }
    }
    fclose(file);
}
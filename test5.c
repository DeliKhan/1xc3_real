#include <stdio.h>
int read_data(char *filename, char *line) //
{

    printf("%s", filename);
    FILE *file = fopen(filename, "r");
    char *results;
    while (fgets(line, sizeof(line), file))
        continue;
    // printf("%s", line);
    fclose(file);
}
int main()
{
    char *filename = "data.txt";
    char line[100];
    // char *filename = "data.txt";
    // char *line = "\0";
    // read_data(filename, line);
    read_data(filename, line);
    printf("%s", line);
}
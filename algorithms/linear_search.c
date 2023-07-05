#include <stdio.h>
#include <string.h>

int main()
{
    int search;
    char input_array[100];
    int array[100];
    char *token;
    char delimiter[] = ",";
    printf("What is the number you are searching for?\n");
    scanf("%d", &search); // hmm, weird but true
    printf("Provide array to search through, with numbers seperated by commas\n");
    scanf("%99s", input_array);
    token = strtok(input_array, delimiter);
    int i = 0;
    while (token)
    {
        array[i] = atoi(token);
        token = strtok(NULL, delimiter);
        printf("%d\n", array[i]);
        i++;
    }
}
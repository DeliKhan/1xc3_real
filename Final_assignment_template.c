#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row_length = 100;
    int column_length = 100;
    int *input_matrix = malloc(sizeof(int) * (row_length * column_length)); // replace int with double or whatever
    // int *input_matrix[100][100];
    char *filename = ""; // input file directory here
    FILE *input_file = fopen(*filename, "r");
    if (file == NULL)
    {
        printf("Error. Unable to open file");
        return 1;
    }
    int number;             // this will store each int in the matrix temporarily
    int row_counter = 0;    // this will count how far down the column we went
    int column_counter = 0; // this will count how far down the row we went
    while (fscanf(input_file, "%d", &number) == 1)
    {
        input_matrix[row_counter][column_counter] = number;
        if (column_length == column_counter - 1) // if we have reach the end of the row, reset column and go down to next row
        {
            column_counter = 0;
            row_counter++;
        }
        else
        {
            column_counter++;
        }
    }
    input_matrix
    ////DO OPERATIONS HERE!!!////
    fclose(input_file);
}
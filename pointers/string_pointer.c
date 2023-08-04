#include <stdio.h>
// Function to find the end of a string using a pointer
void findEndOfString(const char *str)
{
    while (*str != '\0')
    {
        str++; // Move the pointer to the next character
    }
    // Print the last character of the string
    printf("End of string : %c\n", *(str - 1));
}
int main()
{
    // Single string
    const char myString[] = "Hello , this is a test string .";
    // Send the string as a pointer to the function to find the end
    findEndOfString(myString);
}
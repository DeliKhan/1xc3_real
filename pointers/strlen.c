#include <stdio.h>
// Function to find the end of a string using a pointer with a for loop
char findEndOfString(const char *str)
{
    int n;
    for (n = 0; *str != '\0'; str++)
    // interesting, each time it loops, str shrinks (test --> est --> st --> t)
    {
        n++;
    }
    return str[-1]; // Return the last character of the string
    // this doesn't work if str = Hello , this is a test string . If str is broken to ello, this is a test string
    // str[-1] = H (it prints what would have been the letter before it)
}
int main()
{
    // Single string
    const char myString[] = "Hello , this is a test string .";
    // Send the string as a pointer to the function to find the end
    char lastCharacter = findEndOfString(myString);
    printf("End of string : %c\n", lastCharacter);
}

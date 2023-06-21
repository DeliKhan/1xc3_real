#include <stdio.h>

int main(void)
{
    printf("Hello, ");
    printf("World!\n") // This line is missing a semicolon!
}

/* this is a multiline comment
note the following mistakes:
    - the "hello" doesn't get printed despite being before the error?
        - Its cause its compiled, so no
*/
//Hi, lets make sure this works!
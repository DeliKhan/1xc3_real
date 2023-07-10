#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
uint64_t factorial(uint32_t n)
{
    // Base case : factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive case : factorial of n is n multiplied by factorial of(n - 1)
    return n * factorial(n - 1);
}
int main()
{
    uint32_t num = 5;
    uint64_t result = factorial(num);
    printf(" Factorial of %" PRIu32 " is %" PRIu64 "\n", num, result);
}
#include <stdio.h>
#include <float.h>
int main()
{
    printf(" Precision :\n");
    printf(" Float : %d digits \n", FLT_DIG);
    printf(" Double : %d digits \n", DBL_DIG);
    printf(" Long Double : %d digits \n\n", LDBL_DIG);
    printf(" Minimum and Maximum Values :\n");
    printf(" Float : Minimum : %e, Maximum : %e\n", FLT_MIN, FLT_MAX);
    printf(" Double : Minimum : %e, Maximum : %e\n", DBL_MIN, DBL_MAX);
    printf(" Long Double : Minimum : %Le , Maximum : %Le\n", LDBL_MIN,
           LDBL_MAX);
}
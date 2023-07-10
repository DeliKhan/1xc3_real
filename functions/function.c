#include <stdio.h>
float calculateSurfaceArea(float radius)
{
    const float pi = 3.14159;
    float surfaceArea = 2 * pi * radius;
    return surfaceArea;
}
float calculateArea(float radius)
{
    const float pi = 3.14159;
    float area = pi * radius * radius;
    return area;
}
int main()
{
    float radius = 5.0; // in meter
    float surfaceArea = calculateSurfaceArea(radius);
    printf(" Surface area of the circle [m]: %.2f\n", surfaceArea);
    float area = calculateArea(radius);
    printf(" Area of the circle [m ^2]: %.2f\n", area);
    return 0;
}

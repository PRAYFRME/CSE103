#include<stdio.h>

float circle_area(float r)
{
    float area;
    area = 3.1416 * r * r;
    return area;
}

void compare(float area)
{
    if(area>25)
        printf("Greater than 25;");
    else
        printf("Less than 25;");
}

int main()
{
    float r, area;
    printf("Enter radius of the circle : ");
    scanf("%f", &r);

    area =  circle_area(r);
    printf("AREA = %.2f\n", area);

    compare(area);

    return 0;
}


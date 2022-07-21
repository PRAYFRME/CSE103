#include<stdio.h>
int main()
{
    int highest = 0, lowest = 10000, difference, num;
    scanf("%d", &num);
    while(num != -1)
    {

        int num1 = num;
        int num2 = num;
        if(num1 >= highest)
        {
            highest = num1;
        }
        if(num2 <= lowest)
        {
            lowest = num2;

        }
        scanf("%d", &num);
    }
    difference = highest - lowest;
    printf("%d", difference);
    return 0;
}

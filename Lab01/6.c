#include<stdio.h>
int main()
{
    float i = 0, num,count = 0, avg;
    scanf("%f", &num);
    while(num != -1)
    {
        count++;
        i += num;
        avg = i/count;
        scanf("%f", &num);
    }
    printf("%.2f", avg);
    return 0;
}

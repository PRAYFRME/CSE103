#include<stdio.h>
int main()
{
    int number, sum = 0, mod;
    scanf("%d", &number);
    for(; number != 0; number = number / 10){
        mod = number % 10;
        sum += mod;
    }
    printf("%d", sum);

    return 0;
}

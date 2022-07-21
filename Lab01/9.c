#include<stdio.h>
int main()
{
    int i, number, count = 0;
    scanf("%d", &number);

    while (number > 0 && (number % 2 == 0))
    {
        count++;
        number = number / 2;
    }
    printf("%d", count);

    return 0;
}


#include <stdio.h>
int quotient(int number, int divisor)
{
    return number / divisor;
}

int remainder(int number, int divisor)
{
    return number % divisor;
}

int main()
{
    int number;
    int divisor = 10000;
    printf("Enter number (between 1 and 32767): ");
    scanf("%d", &number);
    while (number != 0)
    {
        if (quotient(number, divisor) != 0)
        {
            printf("%d  ", quotient(number, divisor));
            number = remainder(number, divisor);
        }
        divisor /= 10;
    }
    printf("\n");

}

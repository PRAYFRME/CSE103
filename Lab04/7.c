#include <stdio.h>
int result;
int integerPower(int base, int exp)
{
    int result = 1;;
    while (exp != 0)
    {
        result *= base;
        --exp;
    }
    return result;
}
int main()
{
    int base, exp;

    printf("Enter a base number: ");
    scanf("%d", &base);
    printf("Enter an exponent: ");
    scanf("%d", &exp);


    result=integerPower(base,exp);
    printf("Answer = %d", result);
    return 0;
}


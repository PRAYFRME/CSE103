#include <stdio.h>
#include <conio.h>

int gcd( int a, int b)
{
    if ( a == 0)

    {
        return b;
    }
    return gcd (b % a, a);
}


int lcm_fun( int a, int b)
{
    return ( a / gcd(a, b)) * b;
}

int main()
{
    int a, b;
    printf("Enter any two positive numbers \n");
    scanf(" %d %d", &a, &b);

    printf ("LCM of two numbers %d and %d is %d\n", a, b, lcm_fun( a, b));
    return 0;
}

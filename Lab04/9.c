#include <stdio.h>

int gcd(int a,int b)
{
    int g;
    for(int i=1; i <= a && i <= b; ++i)
    {

        if(a % i ==0 && b % i == 0)
            g = i;
    }
    return g;
}
int main()
{
    int n1, n2, i, g, s;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);


    s= gcd(n1, n2);
    printf("G.C.D of %d and %d is %d\n", n1, n2, s);

    return 0;
}


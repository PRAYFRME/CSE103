#include<stdio.h>

int sum(int n);
int main()
{
    int n;
    scanf("%d",&n);
    sum(n);
    return 0;
}

int sum(int n)
{
    int i, result = 0;
    for(i = 1; i < n + 1; i++)
    {
        result = result + i;

        printf("%d + ", i);
    }
    printf(" = %d", result);
}

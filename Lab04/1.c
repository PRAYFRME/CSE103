#include <stdio.h>

void result(int a, int b)
{
    for (int i = a; i < b + 1; i++)
    {
        if (i % 5 == 0 && i % 7 == 0)
            printf("%d ",i);
    }
}

int main()
{
    int x, y;
    scanf("%d %d",&x, &y);
    result(x, y);
    return 0;
}


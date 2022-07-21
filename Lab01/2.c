#include <stdio.h>
int main()
{
    int i, number;
    scanf("%d", &number);
    for(i = 0; i <= 10; i++)
    {
        printf("%d * %d = %d\n", number, i, (number*i));
    }
    return 0;
}

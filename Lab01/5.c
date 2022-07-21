#include<stdio.h>
int main()
{
    int rows, i = 1,j, n = 1;
    scanf("%d", &rows);

    while(i <= rows)
    {
        j = 1;
        while(j <= i)
        {
            printf("%d ", n);

            ++j;
            ++n;
        }
        printf("\n");
        i++;
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int n, row, col, spc;
    printf("Enter the value of rows to show the star pattern: ");
    scanf("%d",&n);
    for(row = 1; row <= n; row++)
    {
        for(spc = 1; spc <= n-row; spc++)
            printf(" ");
        for(col = 1; col <= 2*row-1; col++)
        {
            if(col==1||col==2*row - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(row=n-1; row>=1; row--)
    {
        for(spc = 1; spc <= n-row; spc++)
            printf(" ");
        for(col=1; col <= 2*row-1; col++)
        {
            if(col == 1||col == 2* row-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dice(int n)
{
    srand(time(0));
    int a, b;
    a = 1 + rand()%6;
    b = 1 + rand()%6;
    printf(" Dice 1 : %d \n Dice 2 : %d \n\n",a, b);

    if(a == b == n)
        printf(" You are Winner\n");
    else
        printf(" You are Looser\n");
}

int main()
{
    int n;
    printf("Enter user choices between 1 and 6 : ");
    scanf("%d",&n);

    dice(n);

    return 0;
}

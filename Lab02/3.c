#include<stdio.h>
int main()
{
    int num, fact = 1, i;

    scanf("%d", &num);

    for(i = num; i >= 1; i -= 1){
        fact *= i;
    }
    printf("%d", fact);

    return 0;
}

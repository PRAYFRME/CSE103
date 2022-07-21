#include<stdio.h>
int main()
{
    int number;

    scanf("%d", &number);

    if(number >= 0 && number <= 60){
        printf("Fail");
    }
    else if(number >= 61 && number <= 70){
        printf("C");
    }
    else if(number >= 71 && number <= 80){
        printf("B");
    }
    else if(number >= 81 && number <= 90){
        printf("A");
    }
    else if(number >= 91 && number <= 100){
        printf("A+");
    }

     return 0;
}

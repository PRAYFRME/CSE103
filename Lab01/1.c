#include<stdio.h>
int main()
{
    float x,y;
    scanf("%f",&x);
    scanf("%f",&y);


    if(x>=0 && y>0){
        printf("First Quadrant");
    }
    else if(x<=0 && y>=0){
        printf("Second Quadrant");
    }
    else if(x<=0 && y<=0){
        printf("Third Quadrant");
    }
    else if(x>=0 && y<=0){
        printf("Forth Quadrant");
    }
    else if(x==0 && y==0){
        printf("Origin");
    }
}

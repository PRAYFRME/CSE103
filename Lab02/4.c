#include<stdio.h>
#include<math.h>
int main(){
    double x1 ,x2 , y1, y2, x2minx1=0, y2miny1 = 0, result;

    printf("Input numbers:");

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    x2minx1 = x2 - x1;
    y2miny1 = y2 - y1;

    result = sqrt(x2minx1*x2minx1 + y2miny1*y2miny1);

    if (result == 0){
        printf("\n");
    }else if (result<=10){
            printf("Near\n");
    }else{
        printf("Far\n");
    }
return 0;
}

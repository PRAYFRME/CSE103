#include<stdio.h>

int HW(int n);

int main()
 {
     int n;
     scanf("%d", &n);
     HW(n);
 }

 int HW(int n)
 {
     int i;
     for(i = 0;i < n; i++)
     {
            printf("Hello World\n");
     }
 }


#include<stdio.h>
 int main()
 {
     char calculator;
     int num1,num2;

     printf("Choose a operator from here operator(+,-,*,/,%%): ");
     scanf("%c",&calculator);

     printf("Enter two numbers for calculation: ");
     scanf("%d %d",&num1,&num2);

     switch(calculator)
     {
       case '+':
         printf("%d + %d =\t%d\n",num1,num2,num1+num2);
         break;
       case '-':
         printf("%d - %d =\t%d\n",num1,num2,num1-num2);
         break;
       case '*':
         printf("%d * %d =\t%d\n",num1,num2,num1*num2);
         break;
       case '/':
         printf("%d / %d =\t%d\n",num1,num2,num1/num2);
         break;
       case '%':
         printf("%d %% %d =\t%d\n",num1,num2,num1%num2);
         break;
       default:
         printf("Error! Invalid Operator.");
     }

     return 0;
 }

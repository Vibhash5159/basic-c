# include <stdio.h>
int main (){
 
  float num1;
float num2;
char operation;

printf("enter num1 :");
scanf("%f", &num1);
printf("enter num2 :");
scanf("%f", &num2 );

printf ("enter operation :");\
scanf(" %c", &operation);

switch ( operation){

case '+': 
printf(" %f result is :", num1+num2);
 break;

case '-':
printf("%f result is :", num1-num2);
break;

case '*':
printf("%f result is :",num1*num2);
break;

case '/':
printf("%f result is :",num1/num2);
} 
return 0;
}

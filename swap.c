# include<stdio.h>
int main(){
 int a,b,temp;

      printf("first number=");
        scanf("%d", &a);

     printf("second number=");
       scanf("%d", &b);

temp=a;
a=b;
b=temp;

printf(" the value after swapping is %d and %d", a,b);

return 0;
}
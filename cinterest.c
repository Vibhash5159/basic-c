# include<stdio.h>
# include<math.h>

int main(){
   
  float p,a,r,t;

  printf("Enter pricipal amount= ");
  scanf("%f",&p);

  printf("Enter rate of interest= ");
  scanf("%f",&r);

   printf("Enter time period= ");
   scanf("%f",&t);

  a=p*pow((1+(r/100)),t);

   printf("final amount=%f",a);


return 0;
}
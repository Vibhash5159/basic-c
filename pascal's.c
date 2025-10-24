#include <stdio.h>


int fact(int n){ 
 
 int fact=1;
for (int i=1;i<=n;i++){
fact=fact*i;
}
return fact ;

}

int nCr( int n, int r){

 return fact(n)/(fact (r)*fact(n-r));

}

int main(){
 int n,choice;

    printf("Number of rows to be printed: ");
    scanf("%d", &n);

printf("Choose shape:\n");
printf("1. Triangle\n");
printf("2. Diamond\n");
printf("Enter choice (1 or 2): ");
scanf("%d", &choice);

switch (choice){
case 1: 
 for (int i=0; i<n; i++){
 
 for ( int s=0; s< n-i-1 ;s++){
 printf("  ");
 }
 for (int j=0;j<=i;j++) {
 printf ("%4d", nCr(i,j));
 } 
 printf ("\n");
 
 }
 break;
 

case 2:
 
 for (int i = 0; i < n; i++) {
    for (int s = 0; s < n - i - 1; s++) {
  printf("  ");
 }
  for (int j = 0; j <= i; j++) {
   printf("%4d", nCr(i, j));
  }
 printf("\n");
}
 for (int i = n - 2; i >= 0; i--) {
   for (int s = 0; s < n - i - 1; s++) {
  printf("  ");
  }
  for (int j = 0; j <= i; j++) {
 printf("%4d", nCr(i, j));
  }
  printf("\n");
 }
 break;
 default:
 printf("Invalid choice! Please enter 1 or 2.\n");
 break;
}
}


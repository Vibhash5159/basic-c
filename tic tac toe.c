#include<stdio.h>
// initializing board 
void initialiseboard(char[3][3]
{
    for(int i, i<3,i++}
       { 
          for(int j=0,j<3,j++)
            {
               board [i][j]= ' ' ;
            }
       }
}
// printing of board 
void printboard (char board[3][3])
{
   printf("\n");
  
   printf("%c | %c | %c \n",board[0][0], board[0][1], board[0][2]);
   printf("%c | %c | %c \n",board[1][0], board[1][1], board[1][2]);
   printf("%c | %c | %c \n",board[2][0], board[2][1], board[2][2]);

printf("\n");
}

# include<stdio.h>

char board[3][3] = {'1','2','3','4','5','6','7','8','9'};

void printboard(char board[3][3]);
int checkcondition();

int main()
{ 
    int player;
    int input;
    int turn;
    int game_end = 0; // 0 = false, 1 = true

    printf("The player 1 will have 'X' and player 2 will have 'O'\n");

    printboard(board);
    player = 1;

    for (turn = 0; game_end == 0; turn++)
    {
        if (player == 1)
        {
            printf("Enter the position player 1: ");
            scanf("%d", &input);

            if (input >= 1 && input <= 9)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (input == board[i][j] - '0')
                            board[i][j] = 'X';
                    }
                }

                if (checkcondition() == 1)
                {
                    printf("Player 1 WINS\n");
                    game_end = 1;
                    printboard(board);
                    break;
                }

                if (checkcondition() != 0)
                {
                    printf("It's a draw\n");
                    break;
                }

                printboard(board);
                player++;
            }
            else
            {
                printf("Wrong Input.\n");
                turn--;
                player--;
            }

            printf("Enter the position player 2: ");
            scanf("%d", &input);

            if (input >= 1 && input <= 9)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (input == board[i][j] - '0')
                            board[i][j] = 'O';
                    }
                }

                if (checkcondition() == 1)
                {
                    printf("Player 2 WINS\n");
                    game_end = 1;
                    printboard(board);
                    break;
                }
                else
                {
                    printboard(board);
                }

                player--;
            }
            else
            {
                printf("Wrong Input.\n");
                turn--;
                player++;
            }
        }
    }

    return 0;
}

void printboard(char board[3][3])
{
    printf("\nTIC TAC TOE\n\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkcondition()
{
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        (board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
        (board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
        (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
        (board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
        (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        return 1;
    else
        return 0;
}

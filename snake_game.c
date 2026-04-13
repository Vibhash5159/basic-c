#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int x = 15, y = 15;          // Snake head position
int fruitx, fruity;          // Fruit position
int snakex[100], snakey[100]; // Arrays to store snake body positions
int snakeLength = 1;         // Initial length of snake
char dir = ' ';              // Current direction
  char prevdir=' ';

// Function to hide the console cursor
void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Drawboard() {
    // 1. Move cursor to (0,0) to overwrite the previous frame (No flickering!)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){0, 0});
    SetColor(15);
    

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            
            // 2. Draw Red Walls
            if (i == 0 || i == 29 || j == 0 || j == 29) {
                SetColor(12); // Red
                printf("# ");
            } 
            
            // 3. Draw Pink Fruit
            else if (i == fruitx && j == fruity) {
                SetColor(13); // Bright Pink
                printf("@ ");
            } 
            
            // 4. Draw Snake
            else {
                int printed = 0;
                for (int k = 0; k < snakeLength; k++) {
                    if (i == snakex[k] && j == snakey[k]) {
                        if (k == 0) {
                            SetColor(14); // Yellow Head
                        } else {
                            SetColor(10); // Firozi (Cyan) Body
                        }
                        printf("O ");
                        printed = 1;
                        break;
                    }
                }
                
                // 5. Draw Empty Space
                if (!printed) {
                    printf("  "); 
                }
            }
        }
        printf("\n");
    }
    
    // 6. Reset to Default White for the Score below
    SetColor(7); 
}

void controls() {
    if (_kbhit()) {
        char newdir = getch();

        // Prevent opposite direction change
        if ((newdir == 'w' && prevdir != 's') ||
            (newdir == 's' && prevdir != 'w') ||
            (newdir == 'a' && prevdir != 'd') ||
            (newdir == 'd' && prevdir != 'a')) {
            dir = newdir;   // accept only valid direction
        }
    }


    // Incremented loop with temporary variables
    int prevX = x, prevY = y;
    int tempX, tempY;

    for (int i = 0; i < snakeLength; i++) {
        tempX = snakex[i];
        tempY = snakey[i];
        snakex[i] = prevX;
        snakey[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

    // Update head position
    if (dir == 'w'&& prevdir != 's') x--; // Up
    if (dir == 's'&& prevdir != 'w') x++; // Down
    if (dir == 'a'&& prevdir != 'd') y--; // Left
    if (dir == 'd'&& prevdir != 'a') y++; // Right

    snakex[0] = x;
    snakey[0] = y;
    prevdir=dir;
}

void spawn() {
    fruitx = rand() % (30 - 2) + 1; // Avoid walls
    fruity = rand() % (30 - 2) + 1;
}

int main() {
    
    
    srand(time(0));
    
    HideCursor();
    spawn();

    // Initialize snake head
    snakex[0] = x;
    snakey[0] = y;

    while (1) {
        
        Drawboard();
        SetColor(9);
        printf("\n");
         printf("                       SCORE:%d        ",(snakeLength-1)*10);
        controls();

        // Check if snake eats fruit
        if (x == fruitx && y == fruity) {
            snakeLength++; // Increase length
            spawn();       // Respawn fruit
            
           
        }

        // Boundary check
        if (x <= 0 || x >= 29 || y <= 0 || y >= 29) {
            system("cls");
            SetColor(14);
            printf("Game Over! You hit a wall.\n");
            SetColor(9);
             printf("SCORE:%d        ",(snakeLength-1)*10);
            break;
        }

        // Self-collision check
        for (int i = 1; i < snakeLength; i++) {
            if (x == snakex[i] && y == snakey[i]) {
                system("cls");
                SetColor(14);
                printf("   Game Over! You hit yourself.\n   ");
                SetColor(9);
                 printf("SCORE:%d        ",(snakeLength-1)*10);
                return 0;
            }
        }
        SetColor(15);
        
       

        Sleep(100);// Control speed
    }
    return 0;
}
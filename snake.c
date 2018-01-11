#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void board_print (int board[10][10]){

    printf("-----------------------------------------\n");
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            printf("| ");
            if (board[x][y] == 2) {
                printf("a ");
            }
            if (board[x][y] == 1) {
                printf("X ");
            }
            if (board[x][y] == 0) {
                printf("  ");
            }
        }
            printf("|\n-----------------------------------------\n");
    }
}

int main(void) {
    bool game = true;
    int board[10][10];
    int tail_val = 0;
    char direction = 'd';
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            board[x][y] = 0;
        }
    }
    board [1][1] = 2;
    while (game == true){
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (board[x][y] == 2) {
                    scanf("%s",&direction);
                    if (direction == 'w') {
                        if (board[x - 1][y] == 1) {
                            printf("Game Over!\n");
                            return 0;
                        }
                        else board[x - 1][y] = 2;
                    }
                    else if (direction == 'a') {
                        if (board[x][y - 1] == 1) {
                            printf("Game Over!\n");
                            return 0;
                        }
                        else board[x][y - 1] = 2;
                    }
                    else if (direction == 's') {
                        if (board[x + 1][y] == 1) {
                            printf("Game Over!\n");
                            return 0;
                        }
                        else board[x + 1][y] = 2;
                    }
                    else if (direction == 'd') {
                        if (board[x][y + 1] == 1) {
                            printf("Game Over!\n");
                            return 0;
                        }
                        else board[x][y + 1] = 2;
                    }
                    else {
                        printf("Invalid Command!\n");

                    }
                    board[x][y] = 1;
                    for (int alt_x = 0; alt_x < 10; alt_x++) {
                        for (int alt_y = 0; alt_y < 10; alt_y++) {
                            if (board[alt_x][alt_y] != 0 && board[alt_x][alt_y] != 1 && board[alt_x][alt_y] != 2) {
                                board[alt_x][alt_y] = 0;
                            }
                        }
                    }
                    board_print (board);
                    printf("%d\n",board[1][1]);
                }
            }
        }
    }
}

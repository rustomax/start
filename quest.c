#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void board_print(int board[10][10]){
  system("clear");
  printf("----------------------\n");
  for (int x = 0; x < 10; x++) {
    printf("|");
    for (int y = 0; y < 10; y++) {
      if (board[x][y] == 0) {
        printf("  ");
      }
      if (board[x][y] == 1) {
        printf("O ");
      }
    }
    printf("|\n");
  }
  printf("----------------------\n");
}

int main(void) {
  bool game = true;
  int room = 0;
  int board[10][10];
  char usr;
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      board[x][y] = 0;
    }
  }
  board[5][5] = 1;
  board_print(board);
  while (game == true) {
    bool found = false;
    scanf("%s",&usr);
    for (int x = 0; x < 10 && !found; x++) {
      for (int y = 0; y < 10 && !found; y++) {
          if (board[x][y] == 1) {
            found = true;
          if (usr == 'w'){
              board[x - 1][y] = 1;
          }
          else if (usr == 'a'){
              board[x][y - 1] = 1;
          }
            else if (usr == 's'){
                board[x + 1][y] = 1;
            }
          else if (usr == 'd'){
              board[x][y + 1] = 1;
          }
          board[x][y] = 0;
        }
      }
    }
    board_print(board);
  }
}

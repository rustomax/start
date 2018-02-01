#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void board_print(int board[10][10], int room, bool print_true){
  system("clear");
  printf("Room = %d\n",room);
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
      if (board[x][y] == 2) {
        printf("# ");
      }
    }
    printf("|\n");
  }
  printf("----------------------\n");
  if (print_true == true) {
    printf("This Is A Secret.\nTell Nobody!\n");
  }
}
int main(void) {
  bool game = true;
  int room = 0;
  int board[10][10];
  bool print_true = false;
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      board[x][y] = 0;
    }
  }
  board[5][5] = 1;
  board[0][5] = 2;
  board_print(board, room, print_true);
  while (game == true) {
    print_true = false;
    char usr = 'a';
    bool found = false;
    gets(&usr);
    for (int x = 0; x < 10 && !found; x++) {
      for (int y = 0; y < 10 && !found; y++) {
          if (board[x][y] == 1) {
            found = true;
            if (usr == 'w'){
              //MOVE:
              if (board[x - 1][y] == 0 && x != 0){
                board[x - 1][y] = 1;
                board[x][y] = 0;
              }
              if (board[x - 1][y] == 2) {
                print_true = true;
              }
              //CHANGE ROOM:
              if (x == 0){
                if (room == 0){
                  room = 1;
                }
                board[x][y] = 0;
                board[9][y] = 1;
                print_true = false;
              }
            }
            else if (usr == 'a'){
              //MOVE:
              if (board[x][y - 1] == 0 && y != 0){
                board[x][y - 1] = 1;
                board[x][y] = 0;
              }
              if (board[x][y - 1] == 2) {
                print_true = true;
              }
              //CHANGE ROOM:
              if (y == 0){
                if (room == 0){
                  room = 4;
                }
                board[x][y] = 0;
                board[x][9] = 1;
                print_true = false;
              }
            }
            else if (usr == 's'){
              //MOVE:
              if (board[x + 1][y] == 0 && x != 9){
                board[x + 1][y] = 1;
                board[x][y] = 0;
              }
              if (board[x + 1][y] == 2) {
                print_true = true;
              }
              //CHANGE ROOM:
              if (x == 9){
                if (room == 0){
                  room = 3;
                }
                  board[x][y] = 0;
                  board[0][y] = 1;
                  print_true = false;
              }
            }
            else if (usr == 'd'){
              //MOVE:
              if (board[x][y + 1] == 0 && y != 9){
                board[x][y + 1] = 1;
                board[x][y] = 0;
              }
              if (board[x][y + 1] == 2) {
                print_true = true;
              }
              //CHANGE ROOM:
              if (y == 9){
                if (room == 0){
                  room = 2;
                }
                board[x][y] = 0;
                board[x][0] = 1;
                print_true = false;
              }
            }
            if (board[x - 1][y] == 1 || board[x + 1][y] == 1 || board[x][y - 1] == 1 || board[x][y + 1] == 1) {
            }
            if (board[x + 1][y] == 2 || board[x - 1][y] == 2 || board[x][y + 1] == 2 || board[x][y - 1] == 2) {
            }
              for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                  if (board[x][y] != 1) {
                    board[x][y] = 0;
                  }
                }
              }
            if (room == 0) {
              board[0][5] = 2;
            }
          }
        }
      }
    board_print(board, room, print_true);
  }
}

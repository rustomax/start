#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void board_print(int board[10][10], int room[3][3], bool print_true){
  system("clear");
  for (int room_x = 0; room_x < 3; room_x++) {
    for (int room_y = 0; room_y < 3; room_y++) {
      if (room[room_x][room_y] == 1) {
        printf("Room_X = %d Room_Y = %d\n",room_x, room_y);
      }
    }
  }
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

int change_room(int room[3][3], int *room_x, int *room_y, char direction){
  bool found = false;
  for (int x = 0; x < 3 && !found; x++) {
    for (int y = 0; y < 3 && !found; y++) {
      if (room[x][y] == 1) {
        found = true;
        room[x][y] = 0;
        if (direction == 'w') {
          room[x - 1][y] = 1;
        }
        else if (direction == 'a') {
          room[x][y - 1] = 1;
        }
        else if (direction == 's') {
          room[x + 1][y] = 1;
        }
        else if (direction == 'd') {
          room[x][y + 1] = 1;
        }
      }
    }
  }
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (room[x][y] == 1) {
        *room_x = x;
        *room_y = y;
        return 0;
      }
    }
  }
  return 0; //Compiler Complained
}

int main(void) {
  bool game = true;
  int board[10][10];
  int room[3][3];
  int room_x = 0;
  int room_y = 0;
  char usr = 'a';
  bool print_true = false;
  bool room_change = false;
  bool found_board = false;
  for (int room_x = 0; room_x < 3; room_x++) {
    for (int room_y = 0; room_y < 3; room_y++) {
      room[room_x][room_y] = 0;
    }
  }
  room[1][1] = 1;
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
    room_change = false;
    found_board = false;
    gets(&usr);
    for (int x = 0; x < 10 && !found_board; x++) {
      for (int y = 0; y < 10 && !found_board; y++) {
        if (board[x][y] == 1) {
          found_board = true;
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
              room_change = true;
              change_room(room, &room_x, &room_y, usr);
              board[x][y] = 0;
              board[9][y] = 1;
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
              room_change = true;
              change_room(room, &room_x, &room_y, usr);
              board[x][y] = 0;
              board[x][9] = 1;
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
              room_change = true;
              change_room(room, &room_x, &room_y, usr);
              board[x][y] = 0;
              board[0][y] = 1;
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
              room_change = true;
              change_room(room, &room_x, &room_y, usr);
              room_change = true;
              board[x][y] = 0;
              board[x][0] = 1;
            }
          }
          if (room_change == true) {
            for (int x = 0; x < 3; x++) {
              for (int y = 0; y < 3; y++) {
                if (room[x][y] == 1) {
                  room[x][y] = 0;
                }
                room[room_x][room_y] = 1;
              }
            }
          }
          if (room[1][1] == 0) {
            print_true = false;
          }
          for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
              if (board[x][y] != 1) {
                board[x][y] = 0;
              }
            }
          }
          if (room_x == 1 && room_y == 1){
            board[0][5] = 2;
          }
        }
      }
    }
    board_print(board, room, print_true);
  }
}

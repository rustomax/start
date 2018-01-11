#include <stdio.h>
#include <stdbool.h>

void board_print (int board[3][3]){
  for (int x = 0; x < 3; x++) {
    printf("-------------\n");
    for (int y = 0; y < 3; y++) {
      printf("| ");
      if (board[x][y] == 1) {
        printf("X ");
      }
      if (board[x][y] == 2) {
        printf("O ");
      }
      else if (board[x][y] != 1 && board[x][y] != 2){
        printf("  ");
      }
    }
    printf("|\n-------------\n");
  }
}

int win_check (bool game, int board[3][3]){
  //Player 1

  //Left/Right
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[x][y] == 1 && board[x][y + 1] == 1 && board[x][y - 1] == 1){
        if (y + 1 <= 2 && y - 1 >= 0) {
          printf("Player 1 wins with a horizontal strike!\n");
          game = false;
        }
      }
    }
  }
  //Up/Down
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[x][y] == 1 && board[x + 1][y] == 1 && board[x - 1][y] == 1){
        if (x + 1 <= 2 && x - 1 >= 0) {
        printf("Player 1 wins with a vertical strike!\n");
        game = false;
        }
      }
    }
  }
  //Diagonal
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if ((board[x][y] == 1 && board[x - 1][y + 1] == 1 && board[x + 1][y - 1] == 1) || (board[x][y] == 1 && board[x - 1][y - 1] == 1 && board[x + 1][y + 1] == 1)){
        if ((x + 1 <= 2 && x - 1 >= 0) && (y + 1 <= 2 && x - 1 >= 0)) {
        printf("Player 1 wins with a diagonal strike!\n");
        game = false;
        }
      }
    }
  }
  //Player 2

  //Left/Right
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[x][y] == 2 && board[x][y + 1] == 2 && board[x][y - 1] == 2){
        if (y + 1 <= 2 && y - 1 >= 0) {
          printf("Player 2 wins with a horizontal strike!\n");
          game = false;
        }
      }
    }
  }
  //Up/Down
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (board[x][y] == 2 && board[x + 1][y] == 2 && board[x - 1][y] == 2){
        if (x + 1 <= 2 && x - 1 >= 0) {
          printf("Player 2 wins with a vertical strike!\n");
          game = false;
        }
      }
    }
  }
  //Diagonal
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if ((board[x][y] == 2 && board[x - 1][y + 1] == 2 && board[x + 1][y - 1] == 2) || (board[x][y] == 2 && board[x - 1][y - 1] == 2 && board[x + 1][y + 1] == 2)){
        if ((x + 1 <= 2 && x - 1 >= 0) && (y + 1 <= 2 && x - 1 >= 0)) {
        printf("Player 2 wins with a diagonal strike!\n");
        game = false;
        }
      }
    }
  }
  return game;
}

int main(void) {
  bool game = true;
  int player = 1;
  int x_input, y_input;
  int board[3][3] = {0,0,0,0,0,0,0,0,0};
  int board_full = 0;
  printf("Welcome to Tic Tac Toe!\nType the value of a location to place a token there.\nFirst person to get three in a row wins.\nX goes first.\n");
  printf("player = %d\n",player );
  board_print (board);
  while (game == true) {
    game = win_check (game, board);
    if (game == false) {
      return 0;
    }
    if (board_full == 9) {
      printf("Tie!\n");
      return 0;
    }
    printf("Cordinates ([X][Y])\n[0][0],[0][1],[0][2]\n[1][0],[1][1],[1][2]\n[2][0],[2][1],[2][2]\n");
    printf("X = ");
    scanf("%d",&x_input);
    printf("Y = ");
    scanf("%d",&y_input);
    if (x_input >= 0 && x_input <= 2 && y_input >= 0 && y_input <= 2) {
      if (player == 1 && board[x_input][y_input] == 0) {
        board[x_input][y_input] = 1;
        board_full ++;
        player = 2;
      }
      else if (player == 2 && board[x_input][y_input] == 0) {
        board[x_input][y_input] = 2;
        board_full ++;
        player = 1;
      }
      else printf("Invalid Command\n");
    }
    else printf("Invalid Command\n");
    printf("player = %d\n",player);
    board_print (board);
  }
}

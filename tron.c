#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define BOARDX 48
#define BOARDY 20

void startup(void){
  char user;
  int inc = 0;
  int x = 0;
  int y = 0;
  initscr();
  noecho();
  curs_set(false);
  while (y < 19) {
    mvprintw(y,x, "#");
    refresh();
    usleep(1000);
    x++;
    if (x == 47){
      y++;
      x = 0;
    }
  }
  while (inc < 5) {
    inc++;
    if (inc == 1) {
      mvprintw(6,2,"--------");
      mvprintw(7,2,"|      |");
      mvprintw(8,2,"--    --");
        mvprintw(9,4,"|  |");
       mvprintw(10,4,"|  |");
       mvprintw(11,4,"|  |");
       mvprintw(12,4,"----");
    }
    else if (inc == 2) {
      mvprintw(6,11,"----------");
      mvprintw(7,11,"|   __   |");
      mvprintw(8,11,"|  |__|  |");
      mvprintw(9,11,"|   __  _|");
     mvprintw(10,11,"|  |  | \\");
     mvprintw(11,11,"|  |  |  \\");
     mvprintw(12,11,"----   ---");
    }
    else if (inc == 3) {
      mvprintw(6,22,"----------");
      mvprintw(7,22,"|  ----  |");
      mvprintw(8,22,"|  |  |  |");
      mvprintw(9,22,"|  |  |  |");
     mvprintw(10,22,"|  |  |  |");
     mvprintw(11,22,"|  ----  |");
     mvprintw(12,22,"----------");
    }
    else if (inc == 4) {
      mvprintw(6,33,"-------");
      mvprintw(7,33,"|      \\");
      mvprintw(8,33,"|  |\\   \\");
      mvprintw(9,33,"|  | \\   \\");
     mvprintw(10,33,"|  |  \\   \\");
     mvprintw(11,33,"|  |   \\   \\");
     mvprintw(12,33,"----    ----");
    }
    refresh();
    if (inc < 5) sleep(1);
  }
  inc = 0;
  nodelay(stdscr,true);
  mvprintw(20,0,"Press a to continue");
    while (1) {
      inc ++;
      user = getch();
      if (inc > 4) inc = 1;
      if (inc == 1) mvprintw(6,39,"|");
      if (inc == 2) mvprintw(6,39,"/");
      if (inc == 3) mvprintw(6,39,"-");
      if (inc == 4) mvprintw(6,39,"\\");
      refresh();
      usleep(70000);
      if (user == 'a' || user == 'A') break;
    }
    clear();
    echo();
    endwin();
}

void lose(int board[BOARDX][BOARDY]){
  for (int x = 0; x < BOARDX - 1; x++) {
    for (int y = 0; y < BOARDY - 1; y++) {
      if (board[x][y] == 1) {
        mvprintw(y,x,"O");
        usleep(10000);
        mvprintw(y - 1,x,"|");
        mvprintw(y + 1,x,"|");
        mvprintw(y,x + 1,"-");
        mvprintw(y,x - 1,"-");
        mvprintw(y + 1,x + 1,"\\");
        mvprintw(y + 1,x - 1,"/");
        mvprintw(y - 1, x + 1,"/");
        mvprintw(y - 1,x - 1,"\\");
        refresh();
        sleep(1);
      }
    }
  }
}

void printboard(int board[BOARDX][BOARDY]) {
  initscr();
  noecho();
  for (int x = 0; x < BOARDX - 1; x++) {
    for (int y = 0; y < BOARDY - 1; y++) {
      if (board[x][y] == 0) mvprintw(y,x,"#");
      if (board[x][y] == 1) mvprintw(y,x,"O");
      if (board[x][y] == 2) mvprintw(y,x,"+");
    }
    printw("\n");
  }
  refresh();
}

int game(void){
  char user;
  char direction = 'w';
  int board[BOARDX][BOARDY];
  for (int x = 0; x < BOARDX - 1; x++) {
    for (int y = 0; y < BOARDY - 1; y++) {
      board[x][y] = 0;
    }
  }
  for (int x = 0; x < BOARDX - 1; x++) {
    for (int y = 0; y < BOARDY - 1; y++) {
      board[BOARDX - 1][y] = 2;
      board[x][BOARDY - 1] = 2;
    }
  }
  board[23][17] = 1;
  nodelay(stdscr,true);
  while (1) {
    for (int x = 0; x < BOARDX - 1; x++) {
      for (int y = 0; y < BOARDY - 1; y++) {
        if (board[x][y] == 1) {
          user = getch();
          if (user == 'w' || user == 'a' || user == 's' || user == 'd') direction = user;
          if (direction == 'w') board[x][y - 1] = 1;
          if (direction == 'a') board[x - 1][y] = 1;
          if (direction == 's'){
            board[x][y + 1] = 1;
            usleep(150000);
          }
          if (direction == 'd'){
            board[x + 1][y] = 1;
            usleep(150000);
          }
          if (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd') board[x][y] = 2;
          if ((direction == 'w' && board[x][y - 2] != 0) || (direction == 's' && board[x][y + 2] != 0) || (direction == 'd' && board[x + 2][y] != 0) || (direction == 'a' && board[x - 2][y] != 0)) {
            lose(board);
            clear();
            return 0;
          }
        }
        printboard(board);
      }
    }
  }
}

void gameover(void){

  // Print the field
  for (int y = 0; y < 19; y++) {
    for (int x = 0; x < 47; x++) {
      mvprintw(y,x, "#");
      refresh();
      usleep(1000);      
    }    
  }

  // Print "Game Over" message in a frame
  int const go_len = 9;
  char go_message[go_len] = "GAME OVER";
  char go_char[2];
  go_char[1] = '\0';

  for (int i = 0; i < go_len; i++ ) {
    go_char[0] = go_message[i];
    mvprintw(10, 18 + i, go_char);
    refresh();
    usleep(100000);
  }

  mvprintw(10,17,"|");
  mvprintw(9,17,"-----------");
  mvprintw(10,27,"|");
  mvprintw(11,17,"-----------");
  refresh();

  // Wait for user to press a button
  system("read -n 1 -s -p \"\"");
  echo();

  // clean up
  endwin();
}

int main(void) {
  startup();
  game();
  gameover();
}

/*
--------   ----------   ----------   ---------
|      |   |   __   |   |  ----  |   |        \
--    --   |  |__|  |   |  |  |  |   |   |\    \
  |  |     |   ___ _|   |  |  |  |   |   |  \   \
  |  |     |  |  | \    |  |  |  |   |   |   \   \
  |  |     |  |  |  \   |  ----  |   |   |    \   \
  ----     ----   ---   ----------   -----    -----
*/

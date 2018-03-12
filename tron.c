#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

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
    endwin();
}

int main(void) {
  startup();
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

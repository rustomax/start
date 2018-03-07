#include <stdio.h>
#include <ncurses.h>

void start_window(){
  int usr = 0;
  initscr();
  noecho();
  printw("Don't press the letter a!\n");
  while (usr != 'a'){
    usr = getch();
  }
  endwin();
  echo();
}

int main(void) {
  start_window();
  printf("I told you so...\n");
}

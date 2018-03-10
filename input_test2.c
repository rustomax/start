#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

struct options {
  char *option[3];
  bool position[3];
};

void start_window(){
  struct options choices;
  char walk[5] = "walk";
  char run[4] = "run";
  char hide[5] = "hide";
  choices.option[0] = walk;
  choices.option[1] = run;
  choices.option[2] = hide;
  choices.position[0] = true;
  choices.position[1] = false;
  choices.position[2] = false;
  bool *print_true;
  char *option;
  int usr;
  initscr();
  noecho();
  curs_set(false);
  printw("-%s\n%s\n%s",choices.option[0] ,choices.option[1] ,choices.option[2]);
  while (1) {
    for (int i = 0; i < 3; i++) {
      if (choices.position[i] == 1) {
        usr = 0;
        while (usr == 0) {
          usr = getch();
          if (usr == 'w' && choices.position[0] == false) {
            choices.position[i] = false;
            choices.position[i - 1] = true;
          }
          else if (usr == 's' && choices.position[2] == false) {
            choices.position[i] = false;
            choices.position[i + 1] = true;
          }
        }
        break;
      }
    }
    clear ();
    refresh ();
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        print_true = &choices.position[0];
        option = choices.option[0];
      }
      else if (i == 1) {
        print_true = &choices.position[1];
        option = choices.option[1];
      }
      else if (i == 2) {
        print_true = &choices.position[2];
        option = choices.option[2];
      }
      if (*print_true == true) {
        printw("-");
      }
      printw("%s\n",option);
    }
  }
}
int main(void) {
  start_window();
}

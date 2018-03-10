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

  while (1) {
    //SECTION 1
    for (int i = 0; i < 3; i++) {
      if (choices.position[i] == 1) {
        usr = 0;
        while (usr == 0) {
          usr = getch();
          if (usr == 'w') {
            choices.position[i] = false;
            choices.position[i - 1] = true;
          }
          else if (usr == 's') {
            choices.position[i] = false;
            choices.position[i + 1] = true;
          }
        }
        break;
      }
    }
    /*
    //SECTION 2
      for (int i = 0; i < 3; i++) {
        if (positions[i] == 1) {
          choices.position1 = false;
          choices.position2 = false;
          choices.position3 = false;
          if (positions[i] == 0) {
            choices.position1 = true;
          }
          else if (positions[i] == 1) {
            choices.position2 = true;
          }
          else if (positions[i] == 2) {
            choices.position3 = true;
          }
          break;
        }
      }
    */
    //SECTION 3
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
    system("clear");
  }
}
int main(void) {
  start_window();
}

#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

struct options {
  //NAMES:
  char *option1;
  char *option2;
  char *option3;
  //PLAYER LOC:
  bool position1;
  bool position2;
  bool position3;
};

void start_window(){
  struct options choices;
  char walk[5] = "walk";
  char run[4] = "run";
  char hide[5] = "hide";
  choices.option1 = walk;
  choices.option2 = run;
  choices.option3 = hide;
  int positions[3] = {1,0,0};
  bool *print_true;
  char *option;
  int usr;
  initscr();
  noecho();

  while (1) {
    //SECTION 1
    for (int i = 0; i < 3; i++) {
      if (positions[i] == 1) {
        usr = 0;
        while (usr == 0) {
          usr = getch();
          if (usr == 'w' && positions[i] != 0) {
            positions[i] = 0;
            positions[i - 1] = 1;
          }
          else if (usr == 's' && positions[i] != 2) {
            positions[i] = 0;
            positions[i + 1] = 1;
          }
        }
        break;
      }
    }
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
    //SECTION 3
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        print_true = &choices.position1;
        option = choices.option1;
      }
      else if (i == 1) {
        print_true = &choices.position2;
        option = choices.option2;
      }
      else if (i == 2) {
        print_true = &choices.position3;
        option = choices.option3;
      }
      if (*print_true == true) {
        printw("-");
      }
      printw("%s\n",option);
    }
  }
  endwin();
  echo();
}
int main(void) {
  start_window();
}

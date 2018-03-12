#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

struct lines {
  char *line1;
  char *line2;
  char *line3;
};

int main(void) {
  struct lines rows;
  rows.line1 = (char *) malloc(100 * sizeof(char));
  rows.line2 = (char *) malloc(100 * sizeof(char));
  rows.line3 = (char *) malloc(100 * sizeof(char));
  gets(rows.line1);
  gets(rows.line2);
  gets(rows.line3);
  system("read -n 1 -s -p \"\nPress any key to return to continue...\"");
  system("clear");
  printf("%s\n%s\n%s\n", rows.line1, rows.line2, rows.line3);
  free (rows.line1);
  free (rows.line2);
  free (rows.line3);
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int loc_check (int map[5][5], int *ptr_return_x, int *ptr_return_y){
  for (int x = 0; x < 5; x++) {
      printf("---------------------\n");
    for (int y = 0; y < 5; y++) {
      printf("| ");
      if (map[x][y] == 1) {
        printf("O ");
        *ptr_return_x = x;
        *ptr_return_y = y;
      }
      else printf("  ");
    }
    printf("|\n---------------------\n");
  }
  return 0;
}

int main(void) {
  bool game = true;
  char usr[30];
  int map[5][5];
  int x_alt;
  int y_alt;
  map[4][0] = 0;
  // Value that changes the player's
  map[0][0] = 1;
  // position on the grid
  printf("Type 'help' for a list of commands.\n");
  printf("---------------------\n| O |   |   |   |   |\n---------------------\n---------------------\n|   |   |   |   |   |\n---------------------\n---------------------\n|   |   |   |   |   |\n---------------------\n---------------------\n|   |   |   |   |   |\n---------------------\n---------------------\n|   |   |   |   |   |\n---------------------\n");
    /*
    ADDRESSES
    ----------------------------------------
    {[0][0], [0][1], [0][2], [0][3], [0][4]}
    {[1][0], [1][1], [1][2], [1][3], [1][4]}
    {[2][0], [2][1], [2][2], [2][3], [2][4]}
    {[3][0], [3][1], [3][2], [3][3], [3][4]}
    {[4][0], [4][1], [4][2], [4][3], [4][4]}
    */
  while (game == true) {
    scanf("%s",usr);
    if (strcmp(usr, "move") == 0) {
      printf("ADDRESSES\n");
      printf("----------------------------------------\n");
      printf("{[0][0], [0][1], [0][2], [0][3], [0][4]}\n");
      printf("{[1][0], [1][1], [1][2], [1][3], [1][4]}\n");
      printf("{[2][0], [2][1], [2][2], [2][3], [2][4]}\n");
      printf("{[3][0], [3][1], [3][2], [3][3], [3][4]}\n");
      printf("{[4][0], [4][1], [4][2], [4][3], [4][4]}\n");
      printf("X = ");
      scanf("%d",&x_alt);
      printf("Y = ");
      scanf("%d",&y_alt);
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
          if (map[x][y] == 1) {
              map[x][y] = 0;
          }
        }
      }
      map[x_alt][y_alt] = 1;
      loc_check (map, &x_alt, &y_alt);
      printf("X=%d , Y=%d\n",x_alt, y_alt);
    }
    else if (strcmp (usr, "help") == 0){
      printf("\nHELP\n------------------------------------------------\n");
      printf("help - Displays this screen\nmove - Allows you to set your X and Y cordinates\nexit - Exits the program\n");
    }
    else if (strcmp (usr, "exit") == 0) {
      game = false;
    }
    else printf("Invalid Command\n");
  }
}

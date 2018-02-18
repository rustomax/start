#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct person {
  char *name;
  int age;
};

void startup (struct person *player){
  bool setup = true;
  bool on = true;
  bool confirm;
  char input;
  player->name = (char *) malloc (32 * sizeof(char));
  while (setup == true) {
    printf("Please input your name:\n");
    while (on == true) {
      confirm = true;
      scanf("%s",player->name);
      printf("Do you want to be named %s? (Y/N)\n",player->name);
      while (confirm == true) {
        scanf("%s",&input);
        if (input == 'y' || input == 'Y') {
          confirm = false;
          on = false;
        }
        else if (input == 'n' || input == 'N') {
          printf("Please input a new name:\n");
          confirm = false;
        }
        else printf("Please type y or n.\n");
      }
    }
    confirm = true;
    printf("Please input your age:\n");
    scanf("%d",&player->age);
    printf("Does this look OK?\n\nName = %s\nAge = %d\n\n(y to continue n to redo startup)\n", player->name, player->age);
    while (confirm == true){
      scanf("%s",&input);
      if (input == 'y' || input == 'Y') {
        printf("Very well then.\n");
        confirm = false;
        setup = false;
      }
      else if (input == 'n' || input == 'N') {
        confirm = false;
        on = true;
      }
      else printf("Please type y or n.\n");
    }
  }
}

int main(void) {
  struct person player;
  struct person *ptr_player = &player;
  startup(ptr_player);
  printf("\nPRINTED IN MAIN:\n\n");
  printf("name = %s\nage = %d\n\n", player.name, player.age);
  free(player.name);
}

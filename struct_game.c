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

void create_character (struct person *character){
  bool setup = true;
  bool on = true;
  bool confirm;
  char input;
  character->name = (char *) malloc (32 * sizeof(char));
  while (setup == true) {
    printf("Please input your character's name:\n");
    while (on == true) {
      confirm = true;
      scanf("%s",character->name);
      printf("Do you want your character to be named %s? (Y/N)\n",character->name);
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
    printf("Please input an age:\n");
    scanf("%d",&character->age);
    printf("Does this look OK?\n\nName = %s\nAge = %d\n\n(y to continue n to redo setup)\n", character->name, character->age);
    while (confirm == true){
      scanf("%s",&input);
      if (input == 'y' || input == 'Y') {
        printf("Character created.\n");
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

void check_character_create (struct person *ptr_person1, struct person *ptr_person2, struct person *ptr_person3, int *person_count){
  *person_count = *person_count + 1;
  if (*person_count == 1) {
    create_character (ptr_person1);
  }
  if (*person_count == 2) {
    create_character (ptr_person2);
  }
  if (*person_count == 3) {
    create_character (ptr_person3);
  }
  if (*person_count == 4) {
    printf("You can only create three people.\n");
    *person_count = *person_count - 1;
  }
}

int view_characters (struct person person1, struct person person2, struct person person3, int person_count){
  if (person_count < 1) {
    printf("Oh no, there are no characters!\nCreate a character by selecting 'Create character' in the selection menu\n");
  }
  if (person_count >= 1) {
    printf("\n1.Name = %s\n  Age = %d\n",person1.name, person1.age);
  }
  if (person_count >= 2) {
    printf("\n2.Name = %s\n  Age = %d\n",person2.name, person2.age);
  }
  if (person_count >= 3) {
    printf("\n3.Name = %s\n  Age = %d\n",person3.name, person3.age);
  }
  return 0;
}

void cleanup (struct person *player, struct person *person1, struct person *person2, struct person *person3, int person_count){
  free(player->name);
  if (person_count == 1) {
    free(person1->name);
  }
  if (person_count == 2) {
    free(person2->name);
  }
  if (person_count == 3) {
    free(person3->name);
  }
}

int main(void) {
  int usr;
  char confirm;
  bool game = true;
  bool exit = false;
  int person_count = 0;
  struct person person1;
  struct person person2;
  struct person person3;
  struct person player;
  struct person *ptr_player = &player;
  startup(ptr_player);
  while (game == true) {
    exit = false;
    printf("\nName:%s\tAge:%d\n\nPeople Created = %d\n\nChoose an option:\n1.Create character\n2.Check character stats\n3.Buy item\n4.Quit game\n",player.name, player.age, person_count);
    scanf("%d",&usr);
    if (usr == 1) {
      check_character_create (&person1, &person2, &person3, &person_count);
    }
    else if (usr == 2) {
      view_characters(person1, person2, person3, person_count);
    }
    else if (usr == 3) {
      printf("Still in development!\n");
    }
    else if (usr == 4) {
      printf("Are you sure you would like to exit the game? (Y/N)\n");
      while (exit == false) {
        scanf("%s",&confirm);
        if (confirm == 'y' || confirm == 'Y') {
          printf("As you wish.\n");
          exit = true;
          game = false;
        }
        else if (confirm == 'n' || confirm == 'N') {
          exit = true;
        }
        else printf("Please input y or n\n");
      }
    }
    else printf("Invalid option.\n");
  }
  cleanup (&player, &person1, &person2, &person3, person_count);
}

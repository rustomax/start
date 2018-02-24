#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct person {
  char *name;
  int age;
  char *itemid;
};

struct items {
  bool flashlight;
  bool handgun;
  bool rock;
};

void startup (struct person *player){
  bool setup = true;
  bool on = true;
  bool confirm;
  char input;
  bool name_size = true;
  while (setup == true) {
    player->name = (char *) malloc (32 * sizeof(char));
    printf("Please input your name:\n");
    while (on == true) {
      name_size = true;
      confirm = true;
      while (name_size == true){
        scanf("%s",player->name);
        //BROKEN:
        if (sizeof(player->name) > 32 * sizeof(char)) {
          printf("Name is too large.\n");
        }
        else name_size = false;
        //:BROKEN
      }
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
        printf("\nVery well then.\n");
        confirm = false;
        setup = false;
        system( "read -n 1 -s -p \"\nPress any key to continue...\"" );
      }
      else if (input == 'n' || input == 'N') {
        confirm = false;
        on = true;
        setup = true;
        system("clear");
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
  bool name_size = true;
  while (setup == true) {
    character->name = (char *) malloc (32 * sizeof(char));
    printf("Please input your character's name:\n");
    while (on == true) {
      name_size = true;
      confirm = true;
      while (name_size == true){
        scanf("%s",character->name);
        //BROKEN:
        if (sizeof(character->name) > 32 * sizeof(char)) {
          printf("Name is too large.\n");
        }
        else name_size = false;
        //:BROKEN
      }
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
        printf("\nCharacter created.\n");
        confirm = false;
        setup = false;
        system( "read -n 1 -s -p \"\nPress any key to return to the selection menu...\"" );
      }
      else if (input == 'n' || input == 'N') {
        confirm = false;
        on = true;
        setup = true;
        system("clear");
      }
      else printf("Please type y or n.\n");
    }
  }
}

void check_character_create (struct person *ptr_person1, struct person *ptr_person2, struct person *ptr_person3, int *person_count){
  *person_count += 1;
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
    *person_count -= 1;
    system( "read -n 1 -s -p \"\nPress any key to return to the selection menu...\"" );
  }
}

int view_characters (struct person person1, struct person person2, struct person person3, int person_count){
  if (person_count < 1) {
    printf("Oh no, there are no characters!\nCreate a character by selecting 'Create character' in the selection menu.\n");
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
  system( "read -n 1 -s -p \"\nPress any key to return to the selection menu...\"" );
  return 0;
}

void shop (struct person *player, struct items *player_items, char **item1_name, char **item2_name, char **item3_name){
  bool loop = true;
  bool buy_confirm;
  *item1_name = (char *) malloc (32 * sizeof(char));
  *item2_name = (char *) malloc (32 * sizeof(char));
  *item3_name = (char *) malloc (32 * sizeof(char));
  strncpy (*item1_name, "flashlight", 32);
  strncpy (*item2_name, "handgun", 32);
  strncpy (*item3_name, "rock", 32);
  char item1_availibility[20];
  char item2_availibility[20];
  char item3_availibility[20];
  while (loop == true){
    system("clear");
    if (player_items->flashlight == false) {
      strcpy(item1_availibility, "(availible)");
    }
    else if (player_items->flashlight == true){
      strcpy(item1_availibility, "(sold)");
    }
    if (player_items->handgun == false) {
      strcpy(item2_availibility, "(availible)");
    }
    else if (player_items->handgun == true){
      strcpy(item2_availibility, "(sold)");
    }
    if (player_items->rock == false) {
      strcpy(item3_availibility, "(availible)");
    }
    else if (player_items->flashlight == true){
      strcpy(item3_availibility, "(sold)");
    }
    printf("\nPlease select an item to purchase:\n1.%s %s\n2.%s %s\n3.%s %s\n4.exit shop\n", *item1_name, item1_availibility, *item2_name, item2_availibility, *item3_name, item3_availibility);
    buy_confirm = false;
    char usr;
    scanf("%s",&usr);
    if (usr == '1' && player_items->flashlight == false) {
       player->itemid = *item1_name;
       player_items->flashlight = true;
       buy_confirm = true;
    }
    else if (usr == '2' && player_items->handgun == false) {
      player->itemid = *item2_name;
      player_items->handgun = true;
      buy_confirm = true;
    }
    else if (usr == '3' && player_items->rock == false) {
      player->itemid = *item3_name;
      player_items->rock = true;
      buy_confirm = true;
    }
    else if (usr == '4'){
      loop = false;
    }
    else {
      printf("Invalid selection\n");
      system( "read -n 1 -s -p \"\nPress any key to continue...\"" );
    }
    if ((usr == '1' && buy_confirm == true)|| (usr == '2' && buy_confirm == true) || (usr == '3' && buy_confirm == true)) {
      printf("\nYou have purchased the %s\n",player->itemid);
      system( "read -n 1 -s -p \"\nPress any key to continue...\"" );
    }
  }
  system( "read -n 1 -s -p \"\nPress any key to return to the selection menu...\"" );
}

void check_inventory (char **item1_name, char **item2_name, char **item3_name, struct items player_items){
  if (player_items.flashlight == true) {
    printf("- %s\n",*item1_name);
  }
  if (player_items.handgun == true) {
    printf("- %s\n",*item2_name);
  }
  if (player_items.rock == true) {
    printf("- %s\n",*item3_name);
  }
  if (player_items.flashlight == false && player_items.handgun == false && player_items.rock == false) {
    printf("No items availible.\n");
  }
  system( "read -n 1 -s -p \"\nPress any key to return to the selection menu...\"" );
}

void cleanup (struct person *player, struct person *person1, struct person *person2, struct person *person3, int person_count, char *item1_name, char *item2_name, char *item3_name){
  free(player->name);
  if (person_count >= 1) {
    free(person1->name);
  }
  if (person_count >= 2) {
    free(person2->name);
  }
  if (person_count >= 3) {
    free(person3->name);
  }
  free(item1_name);
  free(item2_name);
  free(item3_name);
}

bool exit_game (bool game){
  char confirm;
  bool exit = false;
  printf("Are you sure you would like to exit the game? (Y/N)\n");
  while (exit == false) {
    scanf("%s",&confirm);
    if (confirm == 'y' || confirm == 'Y') {
      printf("As you wish.\n");
      exit = true;
      game = false;
      system( "read -n 1 -s -p \"\nPress any key to exit...\"" );
      return game;
    }
    else if (confirm == 'n' || confirm == 'N') {
      exit = true;
      game = true;
    }
    else printf("Please input y or n\n");
  }
  return game;
}

int main(void) {
  char usr;
  bool game = true;
  int person_count = 0;
  struct items player_items;
  player_items.flashlight = false;
  player_items.handgun = false;
  player_items.rock = false;
  struct person person1;
  struct person person2;
  struct person person3;
  struct person player;
  struct person *ptr_player = &player;
  char *item1_name;
  char *item2_name;
  char *item3_name;
  char noitem[5] = "none";
  player.itemid = noitem;
  usr = '1';
  startup(ptr_player);
  system("clear");
  while (game == true) {
    printf("_________________________________________________________________________\n");
    printf("\nName:%s\tAge:%d\t  People Created = %d\tCurrent item = %s\n", player.name, player.age, person_count, player.itemid);
    printf("_________________________________________________________________________\n");
    printf("\nChoose an option:\n\n1.Create character\n2.Delete character\n3.Check character stats\n4.Buy item\n5.Check inventory\n6.Quit game\n");
    if (usr != '1' && usr != '2' && usr != '3' && usr != '4' && usr != '5' && usr != '6') {
      printf("\nInvalid option.\n\n");
    }
    scanf("%s",&usr);
    system ("clear");
    if (usr == '1') {
      check_character_create (&person1, &person2, &person3, &person_count);
    }
    else if (usr == '2') {
      printf("Under Development\n");
      system( "read -n 1 -s -p \"\nPress any key to return to the selection menu...\"" );
    }
    else if (usr == '3') {
      view_characters(person1, person2, person3, person_count);
    }
    else if (usr == '4') {
      shop (&player, &player_items, &item1_name, &item2_name, &item3_name);
    }
    else if (usr == '5') {
      check_inventory (&item1_name, &item2_name, &item3_name, player_items);
    }
    else if (usr == '6') {
      game = exit_game (game);
    }
    system ("clear");
  }
  cleanup (&player, &person1, &person2, &person3, person_count, item1_name, item2_name, item3_name);
}

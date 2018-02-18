#include <stdio.h>

struct person1 {
  char *ptr_firstname;
  char *ptr_lastname;
  int age;
};

int main(void) {
  struct person1 player;
  char firstname_array[32];
  char lastname_array[32];
  puts("Please input your first name:");
  scanf("%s",firstname_array);
  player.ptr_firstname = firstname_array;
  puts("Please input your last name:");
  scanf("%s",lastname_array);
  player.ptr_lastname = lastname_array;
  puts("Please input your age:");
  scanf("%d",&player.age);
  printf("Your name is %s %s and you are %d years old.\n",player.ptr_firstname, player.ptr_lastname, player.age);
}

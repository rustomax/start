#include <stdio.h>

struct outline {
  int age;
};
int main(void) {
  struct outline people[3];
  people[1].age = 10;
  people[2].age = 20;
  people[3].age = 30;
  printf("person 1 = %d\nperson 2 = %d\nperson 3 = %d\n",people[1].age, people[2].age, people[3].age);
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct entry {
  char *firstname;
  char *lastname;
  int *age;
  char *gender;
};

int main(void) {
    struct entry person;
    int usr;
    char firstname[32];
    char lastname[32];
    char gender[7];
    int age;
    system("clear");
    while (1 == 1) {
      int confirm = true;
      printf("Select a person to view their database:\n1.Daniel\n2.Veronica\n3.Ella\n");
      scanf("%d",&usr);
      system("clear");
      if (usr == 1) {
        strcpy(firstname, "Daniel");
        strcpy(lastname, "Skybin");
        strcpy(gender, "male");
        age = 14;
      }
      else if (usr == 2){
        strcpy(firstname, "Veronica");
        strcpy(lastname, "Skybin");
        strcpy(gender, "female");
        age = 16;
      }
      else if (usr == 3){
        strcpy(firstname, "Ella");
        strcpy(lastname, "Skybin");
        strcpy(gender, "female");
        age = 12;
      }
      else {
        printf("Invalid selection\n\n");
        confirm = false;
      }
      if (confirm == true) {
        person.firstname = firstname;
        person.lastname = lastname;
        person.gender = gender;
        person.age = &age;
        printf("Name = %s %s\nAge = %d\nSex = %s\n\n",person.firstname, person.lastname,*person.age,person.gender);
      }
    }
}

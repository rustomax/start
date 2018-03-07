#include <stdio.h>

void print_triangle (int usr){
  for (int i = 0; i < usr; i++) {
    for (int j = 0; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main(void) {
  int usr;
  printf("Input the number of rows for your triangle:\n");
  scanf("%d",&usr);
  print_triangle (usr);
}

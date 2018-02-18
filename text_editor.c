#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char * input;
  input = (char *) malloc(100 * sizeof(char));
  for (int i = 0; i < 10; i++) {
    printf("Type letter %d: ", i + 1);
    scanf("%s",&input[i]);
  }
  for (int i = 0; i < 10; i++) {
    printf("input = %s\n",&input[i]);
  }
}

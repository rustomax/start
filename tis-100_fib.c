#include <stdio.h>

int main(void) {
  int first, second, sum;
    first = 0;
    second = 1;
    while(first < 255){
    printf("%d\n", first);
      sum = first + second;
      first = second;
      second = sum;
  }
}

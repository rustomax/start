#include <stdio.h>

int square_me (int x)
{
  int square_of_x = x * x;
  printf("Square: %d\n",square_of_x );
  return square_of_x;
}

int main()
{
  int num;
  printf("input a value to find it's square\n");
  scanf("%d",&num );
  printf("Original: %d\n",num);
  square_me(num);

  return 0;
}

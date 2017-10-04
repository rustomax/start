#include <stdio.h>

int square_me (int x){
    int square_of_x = x * x;
    printf("%d\n",square_of_x );
    return square_of_x;
}
int main(void){
    int num;
    printf("input a value to find it's square\n");
    scanf("%d",&num );
    square_me(num);
}

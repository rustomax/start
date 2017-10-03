#include <stdio.h>

int add (int x){
int sec;
printf("input another value\n");
scanf("%d",&sec);
int sum_of_x = x + sec;
printf("sum of the two numbers = %d\n", sum_of_x);
return sum_of_x;
};




int main(){
printf("input a value\n");
int fir = 0;
scanf("%d",&fir);
add (fir);

    return 0;
}

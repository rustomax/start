#include <stdio.h>

    int add (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int sum_of_x = x + sec;
        printf("sum of the two numbers = %d\n",sum_of_x);
    return sum_of_x;
    };
    int subtract (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int difference_of_x = x - sec;
        printf("difference of the two numbers = %d\n",difference_of_x);
    return difference_of_x;
    };
    int multiply (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int product_of_x = x * sec;
        printf("product of the two numbers = %d\n",product_of_x);
        return product_of_x;
    };
    int divide (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int quotient_of_x = x / sec;
        printf("quotient of the two numbers = %d\n",quotient_of_x);
        return quotient_of_x;
    };
int main(void) {
    printf("choose an operation\n");
    printf("1 = +\n");
    printf("2 = -\n");
    printf("3 = *\n");
    printf("4 = /\n");
    int usr;
    int add_first;
    int subtract_first;
    int multiply_first;
    int divide_first;
    scanf("%d",&usr);

    if (usr == 1) {
        printf("input a value\n");
        scanf("%d",&add_first);
        add (add_first);
        return 0;
    };
    if (usr == 2) {
        printf("input a value\n");
        scanf("%d",&subtract_first);
        subtract (subtract_first);
        return 0;
    };
    if (usr == 3) {
        printf("input a value\n");
        scanf("%d",&multiply_first);
        multiply (multiply_first);
        return 0;
    };
    if (usr == 4) {
        printf("input a value\n");
        scanf("%d",&divide_first);
        divide (divide_first);
        return 0;
    };
}

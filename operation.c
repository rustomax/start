#include <stdio.h>

    int add (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int sum_of_x = x + sec;
<<<<<<< HEAD
        printf("sum of the two numbers = %d\n\n",sum_of_x);
=======
        printf("sum of the two numbers = %d\n",sum_of_x);
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    return sum_of_x;
    };
    int subtract (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int difference_of_x = x - sec;
<<<<<<< HEAD
        printf("difference of the two numbers = %d\n\n",difference_of_x);
=======
        printf("difference of the two numbers = %d\n",difference_of_x);
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    return difference_of_x;
    };
    int multiply (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int product_of_x = x * sec;
<<<<<<< HEAD
        printf("product of the two numbers = %d\n\n",product_of_x);
=======
        printf("product of the two numbers = %d\n",product_of_x);
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
        return product_of_x;
    };
    int divide (int x){
        int sec;
        printf("input another value\n");
        scanf("%d",&sec);
        int quotient_of_x = x / sec;
<<<<<<< HEAD
        printf("quotient of the two numbers = %d\n\n",quotient_of_x);
        return quotient_of_x;
    };
int main(void) {
    int usr;
    int add_first;
    int subtract_first;
    int multiply_first;
    int divide_first;
    begining:
    printf("choose an operation\n");
    printf("--------------------\n");
=======
        printf("quotient of the two numbers = %d\n",quotient_of_x);
        return quotient_of_x;
    };
int main(void) {
    printf("choose an operation\n");
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    printf("1 = +\n");
    printf("2 = -\n");
    printf("3 = *\n");
    printf("4 = /\n");
<<<<<<< HEAD
=======
    int usr;
    int add_first;
    int subtract_first;
    int multiply_first;
    int divide_first;
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    scanf("%d",&usr);

    if (usr == 1) {
        printf("input a value\n");
        scanf("%d",&add_first);
        add (add_first);
<<<<<<< HEAD
        goto begining;
    }
=======
        return 0;
    };
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    if (usr == 2) {
        printf("input a value\n");
        scanf("%d",&subtract_first);
        subtract (subtract_first);
<<<<<<< HEAD
        goto begining;
    }
=======
        return 0;
    };
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    if (usr == 3) {
        printf("input a value\n");
        scanf("%d",&multiply_first);
        multiply (multiply_first);
<<<<<<< HEAD
        goto begining;
    }
=======
        return 0;
    };
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
    if (usr == 4) {
        printf("input a value\n");
        scanf("%d",&divide_first);
        divide (divide_first);
<<<<<<< HEAD
        goto begining;
    }
    else printf("invalid input\n\n");
    goto begining;
=======
        return 0;
    };
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30
}

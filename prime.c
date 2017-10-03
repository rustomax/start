<<<<<<< HEAD
#include <stdio.h>
#include <stdbool.h>

bool check_if_prime (int num) {
    bool isPrime = true;
    for (int i = 2; i < num; i++) {
        if ( num % i == 0 )
            isPrime = false;
}
return isPrime;
}

int main (void)
{
    printf("input a value to check if it is prime\n");
    int val;
    scanf("%d",&val );
    if ( check_if_prime (val) == true ) {
        printf( "%d is prime\n",val );
    }
        else (printf("%d is not prime\n",val ));

        printf("thank you for using this program (: \n");
}
=======
#include <stdio.h>
#include <stdbool.h>

bool check_if_prime (int num) {
    bool isPrime = true;
    for (int i = 2; i < num; i++) {
        if ( num % i == 0 )
            isPrime = false;
}
return isPrime;
}

int main (void)
{
    printf("input a value to check if it is prime\n");
    int val;
    scanf("%d",&val );
    if ( check_if_prime (val) == true ) {
        printf( "%d is prime\n",val );
    }
        else (printf("%d is not prime\n",val ));
}
>>>>>>> 2cfa229c9f3bc2e35b4b7cdfc18dbed684728c30

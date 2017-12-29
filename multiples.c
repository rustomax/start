#include <stdio.h>

int main(void) {
    int i, j, constant, first, last;
    printf("Welcome to the multiple finder!\n");
    printf("This program finds all of the multiples\n");
    printf("between 2 numbers of your choice.\n");
    printf("Please write a constant to be multiplied.\n");
    scanf("%d",&constant);
    printf("Please write the number to start at.\n");
    scanf("%d",&first);
    printf("Please write the number to end at\n");
    scanf("%d",&last);
    printf("\n");
    for (i = first; i <= last; i++) {
        j = constant*i;
        printf("%d\n", j);
    }
    system("pause");
}

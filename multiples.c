#include <stdio.h>

int loop (int i, int j, int constant, int first, int last){
    for (i = first; i <= last; i++) {
        j = constant*i;
        printf("%d\n", j);
    }
    return 0;
}

int main(void) {
    int i, j, constant, first, last;
    printf("Welcome to the multiple finder!\n");
    printf("This program finds all of the multiples\n");
    printf("between a constant and 2 numbers of your choice.\n");
    printf("Please write a constant to be multiplied.\n");
    scanf("%d",&constant);
    printf("Please write the number to start at.\n");
    scanf("%d",&first);
    printf("Please write the number to end at\n");
    scanf("%d",&last);
    printf("\n");
    loop(i, j, constant, first, last);
    system("pause");
}

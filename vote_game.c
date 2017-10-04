#include <stdio.h>
int main (void)
{
    int age;
    printf ("input your age please.\n");
    scanf("%d",&age);
    if (age >= 18) {
        printf("you can vote\n");
}
    else printf("you can not vote\n");
}

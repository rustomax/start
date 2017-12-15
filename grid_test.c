#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    char usr[10];
    bool game;
    int co = 0;
    printf("use the commands north, south, east, or west to move.\n");
    printf("to exit type exit\n");
    printf("----\n");
    printf("|  |\n");
    printf("|O |\n");
    printf("----\n");
    while (game == true) {
        /*
         cordinates:
           -----
           |1,3|
           |0,2|
           -----
        */
        scanf("%s",usr);
        if  (co == 0 && !strcmp (usr, "north") == 1){
            printf("----\n");
            printf("|O |\n");
            printf("|  |\n");
            printf("----\n");
            co = 1;
        };
        if (co == 2 && !strcmp (usr, "north") == 1){
            printf("----\n");
            printf("| O|\n");
            printf("|  |\n");
            printf("----\n");
            co = 3;
        };
        if (co == 1 && !strcmp (usr, "south") == 1){
            printf("----\n");
            printf("|  |\n");
            printf("|O |\n");
            printf("----\n");
            co = 0;
        };
        if (co == 3 && !strcmp (usr, "south") == 1){
            printf("----\n");
            printf("|  |\n");
            printf("| O|\n");
            printf("----\n");
            co = 2;
        };
        if (co == 0 && !strcmp (usr, "east") == 1){
            printf("----\n");
            printf("|  |\n");
            printf("| O|\n");
            printf("----\n");
            co = 2;
        };
        if (co == 1 && !strcmp (usr, "east") == 1){
            printf("----\n");
            printf("| O|\n");
            printf("|  |\n");
            printf("----\n");
            co = 3;
        };
        if (co == 3 && !strcmp (usr, "west") == 1){
            printf("----\n");
            printf("|O |\n");
            printf("|  |\n");
            printf("----\n");
            co = 1;
        };
        if (co == 2 && !strcmp (usr, "west") == 1){
            printf("----\n");
            printf("|  |\n");
            printf("|O |\n");
            printf("----\n");
            co = 0;
        };
        if (!strcmp (usr, "exit") == 1){
            game = false;
        }
    }
}
/*
Things To do:
1. use elsif
2. use an array to store the player's location
3. move print satements into a seperate function
*/


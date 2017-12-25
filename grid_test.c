#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int map_0_north (void){
    printf("----\n");
    printf("|O |\n");
    printf("|  |\n");
    printf("----\n");
    return 0;
};

int map_2_north (void){
    printf("----\n");
    printf("| O|\n");
    printf("|  |\n");
    printf("----\n");
    return 0;
};

int map_1_south (void){
    printf("----\n");
    printf("|  |\n");
    printf("|O |\n");
    printf("----\n");
    return 0;
};

int map_3_south (void){
    printf("----\n");
    printf("|  |\n");
    printf("| O|\n");
    printf("----\n");
    return 0;
};

int map_0_east (void){
    printf("----\n");
    printf("|  |\n");
    printf("| O|\n");
    printf("----\n");
    return 0;
};

int map_1_east (void){
    printf("----\n");
    printf("| O|\n");
    printf("|  |\n");
    printf("----\n");
    return 0;
};

int map_3_west (void){
    printf("----\n");
    printf("|O |\n");
    printf("|  |\n");
    printf("----\n");
    return 0;
};

int map_2_west (void){
    printf("----\n");
    printf("|  |\n");
    printf("|O |\n");
    printf("----\n");
    return 0;
};
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
            map_0_north ();
            co = 1;
        }
        else if (co == 2 && !strcmp (usr, "north") == 1){
            map_2_north ();
            co = 3;
        }
        else if (co == 1 && !strcmp (usr, "south") == 1){
            map_1_south ();
            co = 0;
        }
        else if (co == 3 && !strcmp (usr, "south") == 1){
            map_3_south ();
            co = 2;
        }
        else if (co == 0 && !strcmp (usr, "east") == 1){
            map_0_east ();
            co = 2;
        }
        else if (co == 1 && !strcmp (usr, "east") == 1){
            map_1_east ();
            co = 3;
        }
        else if (co == 3 && !strcmp (usr, "west") == 1){
            map_3_west ();
            co = 1;
        }
        else if (co == 2 && !strcmp (usr, "west") == 1){
            map_2_west ();
            co = 0;
        }
        else if (!strcmp (usr, "exit") == 1){
            game = false;
        }
    }
}
/*
1. use else if: DONE
2. use an array to store the player's location: INCOMPLETE
3. move print satements into a seperate function: DONE
*/

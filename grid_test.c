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
    int grid[2][2] = {
        {0, 0},
        {1, 0}
    };
        /*
        cordinates:
        {[0][0], [0][1]}
        {[1][0], [1][1]}
        */
    char usr[10];
    bool game;
    printf("use the commands north, south, east, or west to move.\n");
    printf("to exit type exit\n");
    printf("----\n");
    printf("|  |\n");
    printf("|O |\n");
    printf("----\n");
    while (game == true) {
        scanf("%s",usr);
        if  (grid[1][0] == 1 && !strcmp (usr, "north") == 1){
            map_0_north ();
            grid[1][0] = 0;
            grid[0][0] = 1;
        }
        else if (grid[1][1] == 1 && !strcmp (usr, "north") == 1){
            map_2_north ();
            grid[1][1] = 0;
            grid[0][1] = 1;
        }
        else if (grid[0][0] == 1 && !strcmp (usr, "south") == 1){
            map_1_south ();
            grid[0][0] = 0;
            grid[1][0] = 1;
        }
        else if (grid[0][1] == 1 && !strcmp (usr, "south") == 1){
            map_3_south ();
            grid[0][1] = 0;
            grid[1][1] = 1;
        }
        else if (grid[1][0] == 1 && !strcmp (usr, "east") == 1){
            map_0_east ();
            grid[1][0] = 0;
            grid[1][1] = 1;
        }
        else if (grid[0][0] == 1 && !strcmp (usr, "east") == 1){
            map_1_east ();
            grid[0][0] = 0;
            grid[0][1] = 1;
        }
        else if (grid[0][1] == 1 && !strcmp (usr, "west") == 1){
            map_3_west ();
            grid[0][1] = 0;
            grid[0][0] = 1;
        }
        else if (grid[1][1] == 1 && !strcmp (usr, "west") == 1){
            map_2_west ();
            grid[1][1] = 0;
            grid[1][0] = 1;
        }
        else if (!strcmp (usr, "exit") == 1){
            game = false;
        }
    }
}
/*
1. use else if: DONE
2. use an array to store the player's location: DONE
3. move print satements into a seperate function: DONE
*/

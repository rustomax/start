#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool game = true;
    int usr;
    int grid[2][2] = {
        {1, 2},
        {3, 4}
    /*
    {[0][0],[0][1]}
    {[1][0],[1][1]}
    */
    };
    int *ptr_loc = &grid[0][0];
    printf("-----\n");
    printf("|O  |\n");
    printf("|   |\n");
    printf("-----\n");
    while (game == true){
        printf("0.Exit\n");
        printf("1.North\n");
        printf("2.South\n");
        printf("3.East\n");
        printf("4.West\n");
        scanf("%d",&usr);
        /*
        -----
        SOUTH
        -----
        */
        if (usr == 2 && ptr_loc == &grid[0][0]) {
            ptr_loc = &grid[1][0];
            printf("-----\n");
            printf("|   |\n");
            printf("|O  |\n");
            printf("-----\n");
        }
        else if (usr == 2 && ptr_loc == &grid[0][1]) {
            ptr_loc = &grid[1][1];
            printf("-----\n");
            printf("|   |\n");
            printf("|  O|\n");
            printf("-----\n");
        }
        /*
        -----
        NORTH
        -----
        */
        else if (usr == 1 && ptr_loc == &grid[1][0]) {
            ptr_loc = &grid[0][0];
            printf("-----\n");
            printf("|O  |\n");
            printf("|   |\n");
            printf("-----\n");
        }
        else if (usr == 1 && ptr_loc == &grid[1][1]) {
            ptr_loc = &grid[0][1];
            printf("-----\n");
            printf("|  O|\n");
            printf("|   |\n");
            printf("-----\n");
        }
        /*
        -----
        EAST
        -----
        */
        else if (usr == 3 && ptr_loc == &grid[0][0]) {
            ptr_loc = &grid[0][1];
            printf("-----\n");
            printf("|  O|\n");
            printf("|   |\n");
            printf("-----\n");
        }
        else if (usr == 3 && ptr_loc == &grid[1][0]) {
            ptr_loc = &grid[1][1];
            printf("-----\n");
            printf("|   |\n");
            printf("|  O|\n");
            printf("-----\n");
        }
        /*
        -----
        WEST
        -----
        */
        else if (usr == 4 && ptr_loc == &grid[0][1]) {
            ptr_loc = &grid[0][0];
            printf("-----\n");
            printf("|O  |\n");
            printf("|   |\n");
            printf("-----\n");
        }
        else if (usr == 4 && ptr_loc == &grid[1][1]) {
            ptr_loc = &grid[1][0];
            printf("-----\n");
            printf("|   |\n");
            printf("|O  |\n");
            printf("-----\n");
        }
        else if (usr == 0) {
            printf("Goodbye!\n");
            game = false;
        }
        else printf("invalid command!\n");
    }
}

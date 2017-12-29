#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
Sorry about all of the goto statements. I'll eventually get around to fixing those.
*/
int view (int view_value){
if (view_value == 1) {
    printf("you are in a dim, seemingly empty room. You see lights shining out of the\n");
    printf("unlocked door in front of you.\n");
}
if (view_value == 2) {
    printf("the room would be identical to the one before if not\n");
    printf("for a singular key sitting on an otherwise empty table in the center of the room.\n");
}
if (view_value == 3) {
    printf("you stand in front of a table in an otherwise empty room.\n");
}
if (view_value == 4) {
    printf("you are again in a similar room, but there are now torches on either side of the exit door.\n");
}
if (view_value == 5) {
    printf("you are standing in front of a stone door\n");
    printf("with two oddly shaped torches hung up beside it.\n");
}
if (view_value == 6) {
    printf("There is a glass capsule in the center of the room containing a medicine bottle.\n");
}
if (view_value == 7) {
    printf("You are standing in front of a large, glass capsule that spans the entire height of\n");
    printf("the room. There is a medicine bottle sitting on the floor inside of the capsule.\n");
}
return 0;
}
bool forward (int f_value){
    bool confirm_return = true;
    if (f_value == 1){
        char confirm[50];
        printf ("there is a door in front of you. ");
        start:
        printf("Would you like to advance through the door?\n");
        scanf("%s",confirm);
        if (!strcmp (confirm, "yes") == 1){
            confirm_return = true;
            printf("as you step into the next room the door behind you slams shut.\n");
            return confirm_return;
        }
        if (!strcmp (confirm, "no") == 1){
            confirm_return = false;
            printf("you back away from the door.\n");
            return confirm_return;
        }
        else printf("invalid command\n");
            goto start;
        }
    if  (f_value == 2){
        char confirm2[50];
        printf("you walk up to the table in front of you and can't help, but notice the key on it.\n");
        start2:
        printf("would you like to pick up the key?\n");
        scanf("%s", confirm2);
        if (!strcmp (confirm2, "yes") == 1){
            confirm_return = true;
            printf("you pick up the key.\n");
            return confirm_return;

        }
        if (!strcmp (confirm2, "no") == 1){
            confirm_return = false;
            printf("you leave the key alone.\n");
            return confirm_return;
        }
        else printf("invalid command\n");
            goto start2;
    }
    if  (f_value == 3){
        char confirm3[50];
        printf("you walk up to the door in front of you with the key in your hand.\n");
        start3:
        printf("would you like to use the key to open the door?\n");
        scanf("%s", confirm3);
        if (!strcmp (confirm3, "yes") == 1){
            confirm_return = true;
            printf("you insert the rusty key into the door lock and unlock the door\n");
            printf("just as the key breaks.\n");
            printf("as you walk into the next room you start to feel dizzy.\n");
            return confirm_return;
        }
        if (!strcmp (confirm3, "no") == 1){
            confirm_return = false;
            printf("you put the key back in you pocket.\n");
            return confirm_return;
        }
        else printf("invalid command\n");
            goto start3;
    }
    if (f_value == 4){
        printf("you walk up to the door on the other end of the room and begin to feel\n");
        printf("very sick.\n");
        confirm_return = true;
        return confirm_return;
    }
    if (f_value == 5){
        printf("you walk forward and hit your head against the door\n");
        printf("needless to say, it's locked.\n");
        confirm_return = false;
        return confirm_return;
    }
    if (f_value == 6){
        printf("you hear a deep voice inside your head:\n");
        printf("Hey, can you hear me? I can see you are becoming very ill. Before you were\n");
        printf("thrown in here you were injected with a deadly poision.\n");
        printf("if you don't find an antidote soon you will die.\n");
        return confirm_return;
    }
    if (f_value == 7){
        printf("you walk up to the glass capsule in the center of the room and start to inspect it,\n");
        printf("before jolting back from the same voice in your head:\n");
        printf("Do you see the medicine bottle inside that container? Thats the antidote.\n");
        printf("It's sealed off shut so you're going to need to solve a puzzle to open it. \n");
        printf("the puzzle is on the back of the container.\n");
        return confirm_return;
        }
}
int main(void) {
    int view_value = 1;
    int forward_value = 1;
    int inventory_value = 0;
    printf("What is your name?\n");
    char name[50];
    scanf("%s",name);
    printf("Hello %s, you have woken up in a dark room with almost no knowladge of who\n",name);
    printf("you are or how you got here. All you have is a lighter. Your job\n");
    printf("is to find a way out. If you need help with any commands type help.\n");
    char commands[50];
    begining:
    scanf("%s",commands);
    if (!strcmp (commands, "help") == 1) {
        printf("-------------------------------------------------\n");
        printf("help - displays all commands\n");
        printf("inventory - displays your current inventory\n");
        printf("view - shows your surroundings\n");
        printf("forward - makes you advance forwards\n");
        printf("(item) - type the name of an item in your inventory to use it\n");
        printf("exit - exits the game\n");
        printf("-------------------------------------------------\n");
        goto begining;}
    if (!strcmp (commands, "exit") == 1) {
        return 0;
    }
    if (!strcmp (commands, "view") == 1) {
        view (view_value);
        goto begining;
    }
    if (!strcmp (commands, "forward") == 1){
        if (forward (forward_value) == true){
                forward_value += 1;
                view_value += 1;
                inventory_value += 1;
                goto begining;
        }
        else goto begining;
    }
    if (!strcmp (commands, "lighter") == 1){
        if (forward_value == 1){
            printf("you become amused by the sparks from the lighter\n");
            goto begining;
        }
        if (forward_value == 2){
            printf("you become amused by the sparks from the lighter.\n");
            goto begining;
        }
        if (forward_value == 3){
            printf("you become amused by the sparks from the lighter.\n");
            goto begining;
        }
        if (forward_value == 4){
            printf("you become amused by the sparks from the lighter.\n");
            goto begining;
        }
        if (forward_value == 5){
            printf("you use the lighter to light the torches and the door opens leading you to\n");
            printf("the next room.\n");
            forward_value += 1;
            view_value += 1;
            inventory_value += 1;
            goto begining;
        }
        if (forward_value == 6){
            printf("you become amused by the sparks from the lighter.\n");
            goto begining;
        }
        if (forward_value == 7){
            printf("you become amused by the sparks from the lighter.\n");
            goto begining;
        }
    }
    if (!strcmp (commands, "key") == 1) {
        if (forward_value == 3) {
            printf("the rust and brittle nature of the key hints to it being\n");
            printf("very old\n");
            goto begining;
        }
    }
    if (!strcmp (commands, "inventory") == 1){
        if (inventory_value == 0) {
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
        if (inventory_value == 1){
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
        if (inventory_value == 2){
        printf("-------------------------------------------------\n");
        printf("lighter - a classic Zippo lighter\n");
        printf("key - can be used to open certain locks\n");
        printf("-------------------------------------------------\n");
        }
        if (inventory_value == 3){
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
        if (inventory_value == 4){
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
        if (inventory_value == 5){
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
        if (inventory_value == 6){
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
        if (inventory_value == 7){
            printf("---------------------------------------------\n");
            printf("lighter - a classic Zippo lighter\n");
            printf("---------------------------------------------\n");
        }
    }
    else printf("invalid command\n");
        goto begining;
}


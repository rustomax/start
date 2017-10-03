#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int view (int view_value){
if (view_value == 1) {
    printf("you are in a dim, seemingly empty room. You see lights shining out of the\n");
    printf("unlocked door in front of you.\n");
}
if (view_value == 2) {
    printf("the room would be identical to the one before if not\n");
    printf("for a singular key sitting on an otherwise empty table in the center of the room.\n");
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
    else printf("error\n");
}

int main(void) {
    int view_value = 1;
    int forward_value = 1;
    printf("What is your name?\n");
    char name[50];
    scanf("%s",name);
    printf("Hello %s, you have woken up in a dark room with almost no knowladge of who\n",name);
    printf("you are or how you got here. All you have is a lighter. Your job\n");
    printf("is to find a way out. If you need help with any commands type help\n");
    char commands[50];
    begining:
    scanf("%s",commands);
    if (!strcmp (commands, "help") == 1) {
        printf("-------------------------------------------------\n");
        printf("help - displays all commands\n");
        printf("inventory - displays your current inventory\n");
        printf("view - shows your surroundings\n");
        printf("forward - makes you advance forwards\n");
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
                forward_value = 2;
                view_value = 2;
                goto begining;
        }
        else goto begining;
}
    else printf("invalid command\n");
        goto begining;
}

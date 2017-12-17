#include <stdio.h>
#include <stdbool.h>
int SYN (int a){
    system("cls");
    printf("A SYN packet is a special type of packet\n");
    printf("used by a node attempting to establish a secure \n");
    printf("connection between itself and another node\n");
    printf("(node A and node B). After node A has sent the\n");
    printf("SYN packet, it will wait for B to respond with an ACK.\n");
    printf("ACK is short for acknowledgement. This means that B is\n");
    printf("acknowledging A's SYN packet and sending a response to A\n");
    printf("saying that it has recieved it's SYN.\n");
    printf("If A does not recieve an ACK it will continue\n");
    printf("to send SYN packets until it times out.\n");
    printf("If however, A does recieve and ACK, then it will\n");
    printf("begin sending informaton to node B\n");
    printf("This type of send and acknowledge system allows\n");
    printf("a secure connection between two nodes\n");
    printf("allowing for the secure data transfer that TCP is based on.\n\n");
    system("pause");
    printf("\n");
    printf("Diagram of informaton sent between A and B\n");
    printf(" A                  B \n");
    printf("---       SYN      ---\n");
    printf("| |       --->     | |\n");
    printf("---                ---\n\n");
    printf("---       ACK      ---\n");
    printf("| |      <---      | |\n");
    printf("---                ---\n\n");
    printf("---       DATA     ---\n");
    printf("| |       --->     | |\n");
    printf("---                ---\n");
    return 0;

}

int main(void) {
    int usr;
    bool on = true;
    printf("Welcome to the TCP/IP information hub.\n");
    printf("Please select one of the options listed below.\n");
    printf("----------------------------------------------\n");
    printf("1.SYN/ACK\n");
    while (on == true){
        scanf("%d",&usr);
        if (usr == 1) {
            SYN (usr);
        }
        if (usr != 1) {
            printf("invalid option\n");
        }
    }
}

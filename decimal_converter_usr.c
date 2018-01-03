#include <stdio.h>
void print_binary(int number)
{
    if (number) {
        print_binary(number >> 1);
        putc((number & 1)? '1' : '0', stdout);
    }
}
void choice_1(void){
  char usr1;
  printf("Input a printable ASCII character to get it's hexadecimal,\noctal, binary, and decimal values.\n");
  while (1 == 1) {
    scanf("%s",&usr1);
    printf("      ASCII     Hex     Oct     Binary     Dec\n");
    printf("-----------------------------------------------------\n");
      printf("|\t");
      printf("%c\t",usr1);
      printf("%X\t",usr1);
      printf("%o\t",usr1);
      print_binary (usr1);
      printf("\t   %d\t    |\n",usr1);
    printf("-----------------------------------------------------\n");
  }
}
void choice_2(void){
int usr2;
printf("Input a number to see it's ASCII, hexadecimal,\noctal, and binary values\n");
while (1 == 1) {
  scanf("%d",&usr2);
  while (usr2 >= 0 && usr2 <= 127) {
    printf("        Dec     Hex     Oct     Binary     ASCII\n");
    printf("-----------------------------------------------------\n");
      printf("|\t");
      printf("%d\t",usr2);
      printf("%X\t",usr2);
      printf("%o\t",usr2);
      print_binary (usr2);
      if (usr2 > 31 && usr2 < 127){
        printf("\t   %c\t    |\n",usr2);
      }
      else if (usr2 == 0) {
          printf("\t   NULL\t    |\n");
      }
      else if (usr2 == 1) {
          printf("\t   SOH\t    |\n");
      }
      else if (usr2 == 2) {
        printf("\t   STX\t    |\n");
      }
      else if (usr2 == 3) {
        printf("\t   ETX\t    |\n");
      }
      else if (usr2 == 4) {
        printf("\t   EOT\t    |\n");
      }
      else if (usr2 == 5) {
        printf("\t   ENQ\t    |\n");
      }
      else if (usr2 == 6) {
        printf("\t   ACK\t    |\n");
      }
      else if (usr2 == 7) {
        printf("\t   BEL\t    |\n");
      }
      else if (usr2 == 8) {
        printf("\t   BS\t    |\n");
      }
      else if (usr2 == 9) {
        printf("\t   HT\t    |\n");
      }
      else if (usr2 == 10) {
        printf("\t   LF\t    |\n");
      }
      else if (usr2 == 11) {
        printf("\t   VT\t    |\n");
      }
      else if (usr2 == 12) {
        printf("\t   FF\t    |\n");
      }
      else if (usr2 == 13) {
        printf("\t   CR\t    |\n");
      }
      else if (usr2 == 14) {
        printf("\t   SO\t    |\n");
      }
      else if (usr2 == 15) {
        printf("\t   SI\t    |\n");
      }
      else if (usr2 == 16) {
        printf("\t   DLE\t    |\n");
      }
      else if (usr2 == 17) {
        printf("\t   DC1\t    |\n");
      }
      else if (usr2 == 18) {
        printf("\t   DC2\t    |\n");
      }
      else if (usr2 == 19) {
        printf("\t   DC3\t    |\n");
      }
      else if (usr2 == 20) {
        printf("\t   DC4\t    |\n");
      }
      else if (usr2 == 21) {
        printf("\t   NAK\t    |\n");
      }
      else if (usr2 == 22) {
        printf("\t   SYN\t    |\n");
      }
      else if (usr2 == 23) {
        printf("\t   ETB\t    |\n");
      }
      else if (usr2 == 24) {
        printf("\t   CAN\t    |\n");
      }
      else if (usr2 == 25) {
        printf("\t   EM\t    |\n");
      }
      else if (usr2 == 26) {
        printf("\t   SUB\t    |\n");
      }
      else if (usr2 == 27) {
        printf("\t   ESC\t    |\n");
      }
      else if (usr2 == 28) {
        printf("\t   FS\t    |\n");
      }
      else if (usr2 == 29) {
        printf("\t   GS\t    |\n");
      }
      else if (usr2 == 30) {
        printf("\t   RS\t    |\n");
      }
      else if (usr2 == 31) {
        printf("\t   US\t    |\n");
      }
      else if (usr2 == 127) {
        printf("\t   DEL\t    |\n");
      }
      printf("-----------------------------------------------------\n");
      break;
    }
  }
}
int main(void) {
  int choice;
  printf("Pick a conversion method\n");
  while (choice != 1 && choice != 2) {
    printf("1.ASCII\n2.Decimal\n");
    scanf("%d",&choice);
    if (choice == 1) {
      choice_1 ();
    }
    else if (choice == 2) {
      choice_2();
    }
    else printf("Invalid Option\n");
  }
}

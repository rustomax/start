#include <stdio.h>

int add (int val, float num1, float num2, float num3, float num4){
    if (val == 1) {
        scanf("%e",&num1);
        val = 2;
    }
    else if (val == 2) {
        scanf("%e",&num2);
        val = 3;
    }
    else if (val == 3) {
        scanf("%e",&num3);
        val = 4;
    }
    else if (val == 4) {
        scanf("%e",&num4);
        val = 5;
    }
    return val;
}
int subtract(int val, float num1, float num2, float num3, float num4){
    if (val == 1) {
        scanf("%e",&num1);
        val = 2;
    }
    else if (val == 2) {
        scanf("%e",&num2);
        val = 3;
    }
    else if (val == 3) {
        scanf("%e",&num3);
        val = 4;
    }
    else if (val == 4) {
        scanf("%e",&num4);
        val = 5;
    }
    return val;
}
int multiply(int val, float num1, float num2, float num3, float num4){
    if (val == 1) {
        scanf("%e",&num1);
        val = 2;
    }
    else if (val == 2) {
        scanf("%e",&num2);
        val = 3;
    }
    else if (val == 3) {
        scanf("%e",&num3);
        val = 4;
    }
    else if (val == 4) {
        scanf("%e",&num4);
        val = 5;
    }
    return val;
}
int divide(int val, float num1, float num2, float num3, float num4){
    if (val == 1) {
        scanf("%e",&num1);
        val = 2;
    }
    else if (val == 2) {
        scanf("%e",&num2);
        val = 3;
    }
    else if (val == 3) {
        scanf("%e",&num3);
        val = 4;
    }
    else if (val == 4) {
        scanf("%e",&num4);
        val = 5;
    }
    return val;
}
int equal(int val, float num1, float num2, float num3, float num4){
    return 0;
}
int main(void) {
    int usr;
    int val = 1;
    float num1 = 0;
    float num2 = 0;
    float num3 = 0;
    float num4 = 0;
    printf("1.add\n2.subtract\n3.multiply\n4.divide\n5.equals");
    scanf("%d",&usr);
    printf("please input a number\n");
    if (usr == 1) {
        val == add (val, num1, num2, num3, num4);
    }
    else if (usr == 2) {
        val == subtract (val, num1, num2, num3, num4);
    }
    else if (usr == 3) {
        val == multiply (val, num1, num2, num3, num4);
    }
    else if (usr == 4) {
        val == add (val, num1, num2, num3, num4);
    }
    else if (usr == 5) {
        val == equal (val, num1, num2, num3, num4);
    }
}

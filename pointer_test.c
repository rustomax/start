int main(void) {
    int on = true;
    int usr;
    int array[4] = {2,0,0,3};
    int *ptr_array;
    while (on == true) {
        printf("1.first value\n");
        printf("2.second value\n");
        printf("3.third value\n");
        printf("4.fourth value\n");
        scanf("%d",&usr);
        if (usr == 1) {
            ptr_array = &array[0];
            printf("value = %d\n",*ptr_array);
        }
        else if (usr == 2) {
            ptr_array = &array[1];
            printf("value = %d\n",*ptr_array);
        }
        else if (usr == 3) {
            ptr_array = &array[2];
            printf("value = %d\n",*ptr_array);
        }
        else if (usr == 4) {
            ptr_array = &array[3];
            printf("value = %d\n",*ptr_array);
        }
        else printf("there are only four values!\n");
    }
}

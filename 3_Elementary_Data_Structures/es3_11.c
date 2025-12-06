#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a[99];

    for(int i = 0; i < 99; i++){
        a[i] = 98 - i;
    }

    puts("after first loop:");
    for(int i = 0; i < 99; i++){
        printf("a[%2d] = %2d\n", i, a[i]);
    }

    for(int i = 0; i < 99; i++){
        a[i] = a[a[i]];
    }

    puts("after second loop:");
    for(int i = 0; i < 99; i++){
        printf("a[%2d] = %2d\n", i, a[i]);
    }

    return EXIT_SUCCESS;
}

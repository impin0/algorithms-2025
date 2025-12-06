#include <stdio.h>
#include <stdlib.h>

#define N 1000

void print_plot(int *arr, int *c);

int main(int argc, char *argv[]){
    int i, j, count = 0;
    int a[N], c[N];

    for(i = 2; i < N; i++){
        a[i] = 1;
    }

    for(i = 2; i < N; i++){
        if(a[i]){
            for(j = i; j * i< N; j++){
                a[i*j] = 0;
            }
        }
    }

    for(i = 2; i < N; i++){
        if(a[i]){
            count++;
        }
        c[i] = count;
    }

    print_plot(a, c);

    return EXIT_SUCCESS;
}
void print_plot(int *arr, int *c){
    for(int i = 0; i < N; i += 22){
        printf("%d:\t", i + 1);
        for(int j = 0; j < *(c + i); j += 10){
            printf("*");
        }
        printf("\n");
    }
}

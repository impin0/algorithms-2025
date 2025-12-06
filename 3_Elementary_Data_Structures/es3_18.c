/* Write a program that determines empirically the number of random positive     *
** less than 1000 that you can expect to generate before getting a repeted value */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VALUE 1000
#define N_OBSERV 100

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n, count, sum = 0;
    int arr[MAX_VALUE] = {0};
    unsigned int seed;

    seed = atoi(argv[1]);

    for(int j = 0; j < N_OBSERV; j++, seed++){
        srand(seed);
        count = 0;
        memset(arr, 0, sizeof(arr));

        for(int i  = 0; i < MAX_VALUE; i++){
            n = rand() % MAX_VALUE;
            if(arr[n]){
                break;
            } else {
                arr[n]++;
                count++;
            }
        }
        sum += count;
    }

    printf("The average number of extraction before a repeated value is: %d\n", sum/N_OBSERV);


    return EXIT_SUCCESS;
}

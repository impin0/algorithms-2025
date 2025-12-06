/* Write a program that determines empirically the number of random *
*  positive integers less than 1000 that you can expect to generate *
*  before getting each value at least once                         */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VALUE 1000
#define N_OBSERV 10

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int seed, count, sum = 0, n, all, cnt;
    int arr[MAX_VALUE];

    seed = atoi(argv[1]);
    srand(seed);

    for(int i = 0; i < N_OBSERV; i++){
        count = 0;
        all = 0;
        memset(arr, 0, sizeof(arr));

        for(int j = 0; all == 0; j++){
            cnt = 0;
            n = rand() % MAX_VALUE;
            arr[n]++;

            if(j >= MAX_VALUE){
                for(int k = 0; k < MAX_VALUE; k++){
                    if(arr[k] == 0){
                        break;
                    } else {
                        cnt++;
                    }
                }
            }
            count++;
            if(cnt == MAX_VALUE){
                break;
            }
        }

        sum += count;
    }

    printf("The average of numbers extracted before getting all the number is: %d\n", sum/N_OBSERV);

    return EXIT_SUCCESS;
}

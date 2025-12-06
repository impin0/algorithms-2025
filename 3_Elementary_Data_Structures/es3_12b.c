#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>

#define N 1000

int main(int argc, char *argv[]){
    int i, j;
    struct timeval start, finish;
    bool a[N];
    printf("array size: %d\n", (int)sizeof(a));

    if(gettimeofday(&start, NULL)){
        fprintf(stderr, "error: gettimeofday()\n");
        return EXIT_FAILURE;
    }

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

    printf("I numeri primi minori di %d, sono:\n", N);
    for(i = 2; i < N; i++){
        if(a[i]) printf("%4d\t", i);
    }
    printf("\n");

    if(gettimeofday(&finish, NULL)){
        fprintf(stderr, "error: gettimeofday()\n");
        return EXIT_FAILURE;
    }

    printf("Total execution time: %d seconds and %d microseconds\n", finish.tv_sec - start.tv_sec, finish.tv_usec - start.tv_usec);

    return EXIT_SUCCESS;
}

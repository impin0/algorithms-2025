#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
    long int i, j;
    int N = atol(argv[1]);
    int *a;
    struct timeval start = {0}, finish = {0};

    a = malloc(sizeof(int) * N);
    if(a == NULL){
        fprintf(stderr, "error: malloc()\n");
        return EXIT_FAILURE;
    }

    if(gettimeofday(&start, NULL) != 0){
        fprintf(stderr, "error: gettimeofday()");
        return EXIT_FAILURE;
    }

    for(i = 2; i < N; i++){
        *(a + i) = 1;
    }

    for(i = 2; i < N; i++){
        //if(*(a + i)){
            for(j = i; j * i< N; j++){
                *(a + (j * i)) = 0;
            }
        //}
    }

    printf("I numeri primi minori di %d, sono:\n", N);
    for(i = 2; i < N; i++){
        if(*(a + i)) printf("%4d\t", i);
    }
    printf("\n");

    if(gettimeofday(&finish, NULL) != 0){
        fprintf(stderr, "error: gettimeofday()");
        return EXIT_FAILURE;
    }

    printf("Time to perform the program: %d seconds and %d microseconds\n", finish.tv_sec - start.tv_sec, finish.tv_usec - start.tv_usec);

    return EXIT_SUCCESS;
}

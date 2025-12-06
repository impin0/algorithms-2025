#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long int i, j;
    int N = atol(argv[1]);
    int *a;

    a = malloc(sizeof(int) * N);
    if(a == NULL){
        fprintf(stderr, "error: malloc()\n");
        return EXIT_FAILURE;
    }

    for(i = 2; i < N; i++){
        *(a + i) = 1;
    }

    for(i = 2; i < N; i++){
        if(*(a + i)){
            for(j = i; j * i< N; j++){
                *(a + (j * i)) = 0;
            }
        }
    }

    printf("I numeri primi minori di %d, sono:\n", N);
    for(i = 2; i < N; i++){
        if(*(a + i)) printf("%4d\t", i);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

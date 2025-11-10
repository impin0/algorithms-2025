/* Write a version of program 3.16 that handles three-dimensional arrays *
 * Program 3.16: Is a two dimensional array allocation program           */

#include <stdio.h>
#include <stdlib.h>

int **malloc2d(int x, int y);
int ***malloc3d(int x, int y, int z);

int main(int argc, char *argv[]){
    
    return EXIT_SUCCESS;
}
int **malloc2d(int x, int y){
    int i;
    int **t = malloc(y * sizeof(int *));
    if(t == NULL){
        fprintf(stderr, "malloc()");
        return NULL;
    }
    for(i = 0; i < y; i++){
        t[i] = malloc(x * sizeof(int));
        if(t[i] == NULL){
            fprintf(stderr, "malloc()");
            return NULL;
        }
    }

    return t;
}
int ***malloc3d(int x, int y, int z){
    int i, j;
    int ***t = malloc(y * sizeof (int **));
    if(t == NULL){
        fprintf(stderr, "malloc()");
        return NULL;
    }

    for(i = 0; i < y; i++){
        t[i] = malloc(x * sizeof(int *));
        if(t[i] == NULL){
            fprintf(stderr, "malloc()");
            return NULL;
        }
        for(j = 0; j < x; j++){
            t[i][j] = malloc(z * sizeof(int));
            if(t[i][j] == NULL){
                fprintf(stderr, "malloc()");
                return NULL;
            }
        }
    }

    return t;
}

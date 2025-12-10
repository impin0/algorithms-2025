/* Count the number of points randomly generated in the unit square    *
 * that can be connected by a straight line of length less than dist   *
 * in d dimensions                                                     */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dim;        //Number of dimensions
    float *coord;   //dinamic array of dimension dim
}Point;

float distance(const Point *a, const Point *b);
float rand_float(void);

int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "usage: %s <n_points> <n_dimensions>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]), i, j;
    Point *arr = malloc(N * (sizeof(Point))) /*, point_dist_min = malloc(2 * (sizeof(Point)))*/;
    float dist_min = 100;

    for(i = 0; i < N; i++){
        arr[i].dim = atoi(argv[2]);
        arr[i].coord = malloc(arr[i].dim * (sizeof(float)));
        for(j = 0; j < arr[i].dim; j++){
            arr[i].coord[j] = rand_float();
        }
    }

    for(i = 0; i < N; i++){
        printf("Point %d: coordinates:\n", i + 1);
        for(j = 0; j < arr[i].dim; j++){
            printf("%f\t", arr[i].coord[j]);
        }
        printf("\n");
    }
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(dist_min > distance(&arr[i], &arr[j]) && i != j){
                dist_min = distance(&arr[i], &arr[j]);
            }
        }
    }

    printf("The closest points are at a distance of: %f\n", dist_min);

    return EXIT_SUCCESS;
}
float rand_float(void){
    return (double) rand() / RAND_MAX;
}
float distance(const Point *a, const Point *b){
    float *d, dist = 0;
    int i;

    d = malloc(a->dim * (sizeof(float)));
    if(d == NULL){
        fprintf(stderr, "error: malloc in distance()\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < a->dim; i++){
        d[i] = a->coord[i] - b->coord[i];
    }

    for(i = 0; i < a->dim; i++){
        dist += d[i] * d[i];
    }

    return sqrt(dist);
}

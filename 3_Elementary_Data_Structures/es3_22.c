/* print out the coordinates of the closest pair of points */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
}Point;

float distance(Point a, Point b);
float rand_float(void);

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "usage: %s <n_points>", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int N = atoi(argv[1]), i;
    Point *arr = malloc(N * (sizeof(Point))), *points_dist_min = malloc(2 * (sizeof(Point)));
    float dist_min = 100;

    for(i = 0; i < N; i++){
        arr[i].x = rand_float();
        arr[i].y = rand_float();
        printf("Point n.%d: x = %f, y = %f\n", i + 1, arr[i].x, arr[i].y);
    }

    for(i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist_min > distance(arr[i], arr[j]) && i != j){
                dist_min = distance(arr[i], arr[j]);
                points_dist_min[0].x = arr[i].x;
                points_dist_min[0].y = arr[i].y;
                points_dist_min[1].x = arr[j].x;                    
                points_dist_min[1].y = arr[j].y;
            }
        }
    }

    printf("The closest points are:\nA: x = %f y = %f\nB: x = %f y = %f\n", points_dist_min[0].x,  points_dist_min[0].y, points_dist_min[1].x, points_dist_min[1].y);

    free(arr);
    return EXIT_SUCCESS;
}
float distance(Point a, Point b){
    float dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
float rand_float(void){
    return (double) rand() / RAND_MAX;
}

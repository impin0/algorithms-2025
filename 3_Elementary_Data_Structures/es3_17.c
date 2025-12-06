#include <stdio.h>
#include <stdlib.h>

#define N 1000

void fill_rand(int *a, int num_elements);

int main(int argc, char *argv[]){
    int num_ele = atoi(argv[1]), c = 0;
    int input[num_ele], count[N] = {0};

    fill_rand(input, num_ele);

    for(int k = 0; k < num_ele; k++){
        printf("%d\t", input[k]);
    }

    for(int i = 0; i < num_ele; i++){
        for(int j = i + 1; j < num_ele; j++){
            if(input[i] == input[j]){
                count[input[i]]++;
                c++;
            }
        }
    }

    printf("We had %d different numbers\n", num_ele - c);
    printf("The non unique numbers are:\n");
    for(int i = 0; i < N; i++){
        if(count[i] > 0){
            printf("%d\t", i);
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}
void fill_rand(int *a, int num_elements){
    
    for(int i = 0; i < num_elements; i++){
        *(a + i) = rand() % N;
    }

}

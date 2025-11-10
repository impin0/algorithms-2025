/* Modify program 3.17 to process input strings individually         *
 * (allocate memory for each string after reading it from the input) *
 * You can assume that all strings have less than 100 characters     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100
#define MAX_STRINGS 5

int main(int argc, char *argv[]){
    char *a[MAX_STRINGS] = {NULL};
    int n;

    for(n = 0; n < MAX_STRINGS; n++){
        a[n] = malloc(MAX_CHAR * sizeof(char));
        if(a[n] == NULL){
            fprintf(stderr, "error: malloc()");
            return EXIT_FAILURE;
        }

        if(fgets(a[n], MAX_CHAR, stdin) == NULL){
            fprintf(stderr, "error: fgets()");
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < n; i++){
        printf("string n.%d: %s", i + 1, a[i]);
    }

    return EXIT_SUCCESS;
}

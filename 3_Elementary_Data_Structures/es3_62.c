/*  Write an efficient program that finds the length of the longest     *
 *  sequence of blanks in a given string, examining as few characters   *
 *  in the string as possible.                                          */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char str[255];
    int max_seq = 0, run = 0;

    strncpy(str, argv[1], 253);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != ' ') continue;
        
        //if(str[i + max_seq] != ' ') continue;

        while(str[i + run] == ' '){
            run++;
        }

        if(max_seq < run){
            max_seq = run;
        }

        i += run - 1;
        run = 0;
    }
    
    printf("The longest sequence of spaces is composed by %d spaces\n", max_seq);

    return EXIT_SUCCESS;
}

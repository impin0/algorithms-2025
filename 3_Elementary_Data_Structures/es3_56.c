/*  Write a program that takes a string as argument, and that prints out
 *  a table giving, for each character that occurs in the string, the 
 *  character and its frequency of occurrence.                      */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char buffer[256];
    int freq[26] = {0};
    char c;
    int len = strlen(argv[1]);

    strncpy(buffer, argv[1], len);

    for(int i = 0; i < len; i++){
        c = buffer[i];
        if(c > 64 && c < 91){
            c -= 65;
        } else {
            c -= 97;
        }

        freq[c]++;
    }

    printf("The characters frequency is:\n");
    for(int i = 0; i < 26; i++){
        printf("%c | %d\n", i+65, freq[i]);
    }

    return EXIT_SUCCESS;
}

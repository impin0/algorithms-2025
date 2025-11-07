/*  Write a program that takes a string as argument, and that prints out
 *  a table giving, for each character that occurs in the string, the 
 *  character and its frequency of occurrence.                      */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s <string> (max 255 characters)\n", argv[0]);
        return EXIT_FAILURE;
    }

    char buffer[256], inverse[256];
    int len = strlen(argv[1]);
    int space = 0;

    strncpy(buffer, argv[1], len);

    for(int i = 0; i < len; i++, space){
        if(buffer[i + space] == 32){
            space++;
        }
        if(space){
            buffer[i] = buffer[i + space];
        }
    }
    len -= space;

    for(int i = 1; i <= len; i++){
        inverse[i - 1] = buffer[len - i];
    }
    inverse[len] = '\0';

    if(strncmp(buffer, inverse, len) == 0){
        printf("The string is palindrome!\n");
    } else {
        printf("The string is NOT palindrome!\n");
    }
    
    return EXIT_SUCCESS;
}

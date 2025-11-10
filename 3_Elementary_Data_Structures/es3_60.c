/* Write a program that replaces substings of more than one blank
 * in a given string by exactly one blank */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void correct_blank_space(char *str);

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char str[255];
    strncpy(str, argv[1], 254);

    correct_blank_space(str);

    printf("The new string is: %s\n", str);

    return EXIT_SUCCESS;
}
void correct_blank_space(char *str){
    int spaces = 0;

    for(int i = 0, succ = 1; str[i] != '\0'; i++, succ++){
        if(str[i + spaces] == 32){
            while(str[succ + spaces] == 32){
                spaces++;
            }
        }

        if(spaces){
            str[i] = str[i + spaces];
        }
    }
}

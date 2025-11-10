/*  Write a program that takes a string as argument and reads a   *
 *  sequence of words (sequences of characters separated by blank *
 *  space) from standard input, printing out those that appear as *
 *  substring somewhere in the argument string                    */   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *str1, char *str2);

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "usage: %s <string>\n", argv[1]);
        return EXIT_FAILURE;
    }

    char str[256], word[30];

    strncpy(str, argv[1], sizeof(str));

    printf("str = %s\n", str);

    while(scanf("%30s", word) == 1){
        if(compare(str, word) == 0){
            printf("%s\n", word);
        }
    }

    return EXIT_SUCCESS;
}
int compare(char *str1, char *str2){

    if(*str2 == '\0'){
        return 0;
    }

    for(int i = 0; str1[i] != '\0'; i++){
        int j = 0;
        while(str1[i + j] != '\0' && str2[2] != '\0' && str1[i + j] == str2[j]){
            j++;
        }
        if(str2[j] == '\0'){
            return 0;
        }
    }

    return 1;
}

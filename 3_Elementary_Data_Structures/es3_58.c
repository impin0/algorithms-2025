/* Suppose that memory for strings is individually allocated.   *
 * Write versions of strcpy() and strcat() that allocate memory *
 * and return a pointer to the new string for the result        */

#include <stdio.h>
#include <stdlib.h>

char *new_strcpy(char *src);
char *new_strcat(char *str1, char *str2);
int new_strlen(char *str);

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s <str1> <str2>", argv[0]);
        return EXIT_FAILURE;
    }

    char *new_str;

    new_str = new_strcpy(argv[1]);

    printf("new_str post cpy() = %s\n", new_str);

    new_str = new_strcat(argv[1], argv[2]);

    printf("new_str post cat() = %s\n", new_str);

    return EXIT_SUCCESS;
}
char *new_strcpy(char *src){
    char *dest = malloc(sizeof(char) * new_strlen(src));
    if(dest == NULL){
        fprintf(stderr, "malloc() failure\n");
        return NULL;
    }

    for(int i = 0; (*(dest + i) = *(src + i)) != 0; i++);

    return dest;
}
char *new_strcat(char *str1, char *str2){
    int i = 0;
    char *new_str = malloc(sizeof(char) * (new_strlen(str1) + new_strlen(str2) - 1));
    if(new_str == NULL){
        fprintf(stderr, "malloc() failure\n");
        return NULL;
    }

    for(; (*(new_str + i) = *(str1 + i) ) != '\0'; i++);

    *(new_str + i) = 'a';

    for(int k = 0; (*(new_str + i) = *(str2 + k)) != '\0'; i++, k++);

    return new_str;
}
int new_strlen(char *str){
    int len;
    char *b = str;
    while(*b++);
    len = b - str;

    return len;
}

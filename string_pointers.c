#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[]){
    int i;
    char string[30];
    char *strptr;
    strptr = string;
    strcat(string,argv[1]);
    for(i = 0; i < strlen(argv[1]); ++i){
        printf("%d",i);
        printf("%s", string);
    }
    putchar('\n');
    for(i = 0;i < strlen(string);++i){
        printf("%c", string[i]);
    }
    putchar('\n');
    for(i = 0; i < sizeof(strptr); ++i){
        printf("%c", *strptr);
        strptr++;
    }

    putchar('\n');
}   


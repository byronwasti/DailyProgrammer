#include <stdlib.h>
#include <stdio.h>
#define MAXBUFFERSIZE 80

int main(void) {
    char ch;
    char Name[MAXBUFFERSIZE];
    char Age[MAXBUFFERSIZE];
    char Reddit_Name[MAXBUFFERSIZE];
    int ch_count;

    printf("Good day! Let me get to know you some...\n\n");
    ch = 0;
    ch_count = 0;
    printf("What might your name be? ");
    while(ch != '\n') {
        ch = getchar();
        Name[ch_count] = ch;
        ch_count++;
    }
    Name[--ch_count] = 0;

    ch = 0;
    ch_count = 0;
    printf("And your age? ");
    while(ch != '\n') {
        ch = getchar();
        Age[ch_count] = ch;
        ch_count++;
    }
    Age[--ch_count] = 0;

    ch = 0;
    ch_count = 0;
    printf("What about your Reddit username? ");
    while(ch != '\n') {
        ch = getchar();
        Reddit_Name[ch_count] = ch;
        ch_count++;
    }
    Reddit_Name[--ch_count] = 0;

    printf("\nGreat!  So your name is %s, you're %s, and on Reddit, you're called %s.\n", Name, Age, Reddit_Name);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int MAX = 10, i = 2;

unsigned int 
fib( unsigned long a, unsigned long b){
    if ( i < MAX){
        i++;
        a = a + b;
        printf("%9d",a);
        if ( i % 5 == 0) putchar('\n');
        fib(b, a);
    }
    return b;
}

int main( int argc, char *argv[]){

    if (argc > 1) MAX = atoi(argv[1]);

    printf("This will be the number of iterations: %d\n\n", MAX);
    printf("%9d%9d", 1, 1);
    fib(1,1);

    putchar('\n');
}   


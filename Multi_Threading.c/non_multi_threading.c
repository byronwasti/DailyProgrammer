#include <stdio.h>

#define LIMIT 10000000

int main()
{
    int x = 0, y = 0;

    printf("x: %d, y: %d\n", x, y);

    while(++y < LIMIT);
    
    printf("y increment finished\n");
    
    while(++x < LIMIT);
    printf("x increment finished\n");

    printf("x: %d, y: %d\n", x, y);
    return 0;
}

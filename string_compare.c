#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char    name[80];
    int     price;
} element;

void fill(element* arr, int n){
    int price, i;
    char name[80];
    for (i = 0; i < n; ++i){
        scanf("%s %i", name, &price);
        strcpy(arr[i].name, name);
        arr[i].price = price;
    }
}

int main(void){
    int n, i, j;
    fscanf(stdin, "%i\n", &n);

    element* old = malloc(sizeof(element) * n);
    element* new = malloc(sizeof(element) * n);

    fill(old, n);
    fill(new, n);

    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            if (strcmp(old[i].name, new[j].name) != 0)
                continue;

            if(old[i].price != new[j].price){
                int difference = new[j].price - old[i].price;
                printf("%s %s%i\n", old[i].name, difference < 0 ? "" : "+", difference);
            }
        }
    }

    free(old);
    free(new);

    return 0;
}

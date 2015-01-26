#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
    int number_to_check = 100000000;

    if (argc > 1) {
      number_to_check = atoi(argv[1]);
    }   

    int primes_found = 0;
    int *primes = (int*)calloc(number_to_check,sizeof(int));

    int i;
    for (i = 2; i < number_to_check; i++) {
        if (primes[i] == 1) continue; 
        primes_found ++; 
        if (i >= number_to_check/i) continue;
        int j;
        for (j = i*i; j < number_to_check; j+=i) {
            primes[j] = 1;
        }
    }

    free(primes);
    printf("%s: %d\n", argv[0], primes_found);
}

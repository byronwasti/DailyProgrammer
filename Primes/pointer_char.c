#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
    unsigned int number_to_check = 100000000;

    if (argc > 1) {
      number_to_check = atoi(argv[1]);
    }
        
    unsigned int primes_found;
    char *primes = malloc(number_to_check);
    char *prime_ptr = primes, *sweeper, *ender = (primes + number_to_check);

    unsigned int i;
    for ( i = 2; i < number_to_check; i++){
        if( *prime_ptr == 'n'){
             //printf("%d not primes\n", i);
             prime_ptr++;
             continue;
        }
        //printf("%d at location %d\n", i, prime_ptr);
        //printf("%d is prime_ptr\n", prime_ptr);
        primes_found ++;
        prime_ptr++;
        if (i >= number_to_check/i){
             //printf("%d are primes, but not sequenced\n", i);
             continue;
        }
        for( sweeper = (primes + (i*i)) - 2; sweeper < ender; sweeper+=i){
            //printf("%d are primes and sequenced\n", sweeper - primes + 2);    
            //printf("%d is sweeper, %d is sweeper - primes\n", sweeper, sweeper - primes);
            *sweeper = 'n';
            //printf("%c is what sweeper sets\n", *sweeper);
        }
    }

    free(primes);
    printf("Number of primes found: %d\n", primes_found);
}
        

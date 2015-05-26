#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv){
  unsigned int number_to_check = 100000000;
  //unsigned int number_to_check = 1000000;

  if (argc > 1) {
    number_to_check = atoi(argv[1]);
  }

  unsigned int primes_found;
  char *primes = malloc(number_to_check);

  unsigned int i;
  for ( i = 2; i < number_to_check; i++){
    if( primes[i] == 'n') continue;
    primes_found ++;
    if (i >= number_to_check/i+1) continue;
    unsigned int j;
    for( j= i*i; j < number_to_check; j+=i){
      primes[j] = 'n';
    }
  }

  free(primes);
  printf("Number of primes found: %d\n", primes_found);
}


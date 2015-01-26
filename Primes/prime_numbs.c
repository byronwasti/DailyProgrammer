// A prime number generator
// Mainly for my own education

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	unsigned int MAX = atoi(argv[1]);
	fprintf(stdout, "%d: Is the max number\n", MAX);

	// Set up the array to store primes
	unsigned int *_PRIMES_ = malloc( (MAX/2) * sizeof(int));
	unsigned int _NUM_PRIMES_;
	unsigned int new_prime;

	// Set up iterators
	unsigned int i;
	unsigned int j;

	_PRIMES_[0] = 2;
	_NUM_PRIMES_ = 1;

	// This will sweep i from 2 to MAX
	for(i = 2; i <= MAX ; ++i){

		// This loop will test i against all known primes
		for(j = 0; j < _NUM_PRIMES_ ; ++j){
			if (sqrt(i)+1 < _PRIMES_[j]) break;

			if (i % _PRIMES_[j] != 0){
				new_prime = i;
			}
			if (i % _PRIMES_[j] == 0){
				new_prime = 0;
				break;
			}
		}
		
		if (new_prime != 0){
			_PRIMES_[_NUM_PRIMES_] = new_prime;
			_NUM_PRIMES_++;
		}

	}
	
	if ( atoi(argv[2]) == 1){
	for(i = 0; i < _NUM_PRIMES_; ++i){
		if( MAX < 100000 ){ 
			fprintf(stdout, "%6d", _PRIMES_[i]);
			if (i % 10 == 9) putchar('\n');
		}
		else{
			fprintf(stdout, "%9d", _PRIMES_[i]);
			if (i % 5 == 4) putchar('\n');
		}
	}
	}
	putchar('\n');
	putchar('\n');
	fprintf(stdout, "There are %d primes.\n", _NUM_PRIMES_);

	free(_PRIMES_);

	return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>


unsigned int number_to_check=100000000;

void *check_primes(int i, unsigned int *p){
    printf("X thread started\n");
    unsigned int j;
    for (j = i*i; j < number_to_check; j+=i){
        printf("X's j:%d\n",j);
        p[j] = 1;
    }
    printf("X thread ended\n");
    return NULL;
}

int main(int argc, char **argv) {
    unsigned int initializer, k;
    pthread_t second;

    if (argc > 1) {
      number_to_check = atoi(argv[1]);
    }   

    unsigned int primes_found = 0;
    unsigned int *primes = (int*)calloc(number_to_check,sizeof(int));

    unsigned int i;
    for (i = 2; i < number_to_check; i++) {
        printf("%d\n", i);
        if (primes[i] == 1) continue; 
        primes_found ++; 
        if (i >= number_to_check/i) continue;
        unsigned int j;
        if (initializer == 0){
            if(pthread_create(&second, NULL, check_primes(i,primes), &k)){
                printf("Error creating second thread\n");
                return 1;
            }
            initializer = 1;
        }
        else{ 
            printf("Y's thread starts\n");
            for (j = i*i; j < number_to_check; j+=i) {
                primes[j] = 1;
            }
            printf("Y's thread is over\n");
            if(pthread_join(second,NULL)){
                printf("Error joining second thread with first\n");
                return 2;
            }
            initializer = 0;
        }
    }

    free(primes);
    printf("%s: %d\n", argv[0], primes_found);
}

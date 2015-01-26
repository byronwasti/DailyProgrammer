#include <stdlib.h>
#include <stdio.h>


unsigned long gcd( unsigned long a, unsigned long b){
	if (b != 0){
		return gcd(b, a % b);
	}
	else return a;
}

int main( int argc, char *argv[]){
	unsigned long a, b;
	if (argc >2){
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}
	else {
		printf("Please the first number: ");
		scanf("%d",&a);
		printf("Please the second number: ");
		scanf("%d",&b);
	}

	printf("%d is the GCD.\n", gcd(a, b));

}

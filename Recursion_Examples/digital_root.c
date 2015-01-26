#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int digital_root(unsigned int n){
	while (n > 9) 
		n = n % 10 + digital_root(n/10);
	return n;
}

int main( int argc, char *argv[]){
	unsigned int numb;
	printf("Please input the number you wish to find the digital root of: ");
	scanf("%d", &numb);
	numb = digital_root(numb);
	printf("%d", numb);
	putchar('\n');
}

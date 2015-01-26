#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum { ARR_LEN = 100};

int main()
{
	int i, *pNum = malloc(ARR_LEN * sizeof(int));
	if (pNum == NULL)
	{ 
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}
	
	srand( (unsigned)time(NULL) );

	for ( i=0; i < ARR_LEN; ++i)
		pNum[i] = rand() % 10000;

	printf("\n %d random numbers between 0 and 9999:\n", ARR_LEN);
	for (i=0; i<ARR_LEN;++i)
	{
		printf("%6d",pNum[i]);
		if (i % 10 == 9) putchar('\n');
	}
	free(pNum);
	return 0;
}

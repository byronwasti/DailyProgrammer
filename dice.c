#include <stdlib.h>
#include <stdio.h>

void main(void){
	int N, M, i;
	char trash, newline;
	printf("Hello! Input your dice values!\n");
	scanf("%d%c%d%c",&N,&trash,&M,&newline);

	srand((unsigned) time(NULL));
	for (i = 0; i < N; ++i){
		printf("%d ",rand() % M + 1);
	}
	putchar('\n');
}

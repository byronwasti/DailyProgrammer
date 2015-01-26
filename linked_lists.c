#include <stdio.h>
#include <stdlib.h>


typedef struct _tile {
		int x;
		int y;
		struct _tile *next;
}tile;


int main(){
		tile *value,*head;

		int n;
		while(n<5){

				value= (tile *)malloc(sizeof(tile)); //line 18
				printf("enter value  x: ");
				scanf("%d",&value->x);
				printf("enter value  y: ");
				scanf("%d",&value->y);
				printf("\n ");
				value->next = head; //line 24
				head = value;  //line 25
				++n;
		}


		while(value!=NULL){
				printf("your value x : %d | your value y : %d \n",value->x,value->y);
				value=value->next;
		}

		return 0;

}

#include <stdlib.h>
#include <stdio.h>

static unsigned int MAX_WORD_SIZE = 20;

typedef struct{
	char str[MAX_WORD_SIZE]; // The word
	int occ; // Number of occurences
} Word;
	

int main ()
{
   FILE *fp;
   char c;
  
   fp = fopen("test.txt","r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      { 
          break ;
      }
      printf("%c", c);
   }
   fclose(fp);
   return(0);
}

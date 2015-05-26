#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct {
  int number;
  int suit;
  int chosen;
} card;


void shuffleDeck( int* DECK ){
  int i;
  int c1, c2;
  for (i = 0; i < 52; i++){
    c1 = rand()%52;
    c2 = rand()%52;
    if( c1 != c2 ){
      DECK[c1] ^= DECK[c2];
      DECK[c2] ^= DECK[c1];
      DECK[c1] ^= DECK[c2];
    }
  }
}


card * populateDeck( void ) {
  int i, j;
  card* bDECK = (card *)malloc(52 * sizeof(card));
  int* sDECK = (int *)malloc(52 * sizeof(int));

  card* DECK = (card *)malloc(52 * sizeof(card));

  for (i = 0; i < 52; i++){
    sDECK[i] = i;
  }
  shuffleDeck(sDECK);

  for ( i = 0; i < 4; i++){

    // j is offset from zero for obvious reasons
    // DECK index is fixed to allow for that
    for ( j = 1; j < 14; j++){ 
      bDECK[ i * 13 + j-1].number = j;
      bDECK[ i * 13 + j-1].suit = i;
    }
  }

  for (i = 0; i < 52; i++){
    DECK[i] = bDECK[sDECK[i]];
  }

  free(sDECK);
  free(bDECK);
  return DECK;
}


card drawCard( card* DECK ){
  int i = rand()%52;
  if ( DECK[i].chosen == 0){
    DECK[i].chosen = 1;
    return DECK[i];
  }
  else{
    return drawCard(DECK);
  }
}


void printDeck( card* DECK ){
  int i;
  for( i = 0; i < 52; i++){
    printf("%d, %d\n", DECK[i].number, DECK[i].suit);
  }
}


int main( int argc, char * argv[]){
  int PLAYERS = 4;
  srand(time(NULL));
  if (argc > 1){
    PLAYERS = atoi(argv[1]);
  }

  card* DECK = populateDeck();
  printDeck( DECK );

  //printDeck(DECK);
  //card FLOP = drawCard(DECK);
  //printf("%d, %d \n", FLOP.number, FLOP.suit);

  //printf("%d, %d \n", DECK[i].number, DECK[i].suit);
}

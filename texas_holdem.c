#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


typedef struct {
  int number;
  int suit;
} card;

typedef struct{
  card c1;
  card c2;
} hand;

typedef struct{
  char number[6];
  char suit[9];
} str_card;


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
  static int i;
  card c = DECK[i];
  i++;
  return c;
}


void printDeck( card* DECK ){
  int i;
  for( i = 0; i < 52; i++){
    printf("%d, %d\n", DECK[i].number, DECK[i].suit);
  }
}


str_card interpretCard( card C ){
  str_card sC;
  switch(C.number){
    case 1: sprintf(sC.number, "ACE"); break;
    case 11: sprintf(sC.number, "JACK"); break;
    case 12: sprintf(sC.number, "QUEEN"); break;
    case 13: sprintf(sC.number, "KING"); break;

    default: sprintf( sC.number, "%d",C.number);
  }

  switch(C.suit){
    case 0: sprintf(sC.suit, "HEARTS"); break;
    case 1: sprintf(sC.suit, "SPADES"); break;
    case 2: sprintf(sC.suit, "CLUBS"); break;
    case 3: sprintf(sC.suit, "DIAMONDS"); break;
  }
  //printf("%s of %s\n", sC.number, sC.suit);
  return sC;
}


int main( int argc, char * argv[]){
  int PLAYER_COUNT = 4, i, j, onCard = 0;

  srand(time(NULL));
  if (argc > 1){
    PLAYER_COUNT = atoi(argv[1]);
  }

  card* DECK = populateDeck();
  hand* PLAYERS = (hand *)malloc(PLAYER_COUNT * sizeof(hand));
  card* TABLE = (card *)malloc(5 * sizeof(card));
  
  /* GAMEPLAY */

  for (int i = 0; i < PLAYER_COUNT; i++){
    PLAYERS[i].c1 = drawCard(DECK);
    PLAYERS[i].c2 = drawCard(DECK);
  }

  for(i = 0; i < PLAYER_COUNT; i++){
    str_card c1 = interpretCard(PLAYERS[i].c1);
    str_card c2 = interpretCard(PLAYERS[i].c2);
    printf("PLAYER %d : %s of %s\n", i+1, c1.number, c1.suit );
    printf("           %s of %s\n", c2.number, c2.suit);
  }

  putchar('\n');
  for (int i = 0; i < 5; i++){
    TABLE[i] = drawCard(DECK);
    if(i == 0){ printf("The FLOP:\n");}
    if(i == 3){ printf("The TURN:\n");}
    if(i == 4){ printf("The RIVER:\n");}
    
    str_card ctable = interpretCard(TABLE[i]);
    printf("    %s of %s\n", ctable.number, ctable.suit);
  }

  //interpretCard( PLAYERS[i].c1 );


  /* FREE UP MEMORY */
  free(DECK);
  free(PLAYERS);
  free(TABLE);
  return 0;
}

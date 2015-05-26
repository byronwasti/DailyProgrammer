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


// Prints out the card in a standard 18 char format
void interpretCard( card C ){
  char number[6];
  char suit[9];
  char OUT[18];

  switch(C.number){
    case 1: sprintf(number, "ACE"); break;
    case 11: sprintf(number, "JACK"); break;
    case 12: sprintf(number, "QUEEN"); break;
    case 13: sprintf(number, "KING"); break;

    default: sprintf(number, "%d",C.number);
  }

  switch(C.suit){
    case 0: sprintf(suit, "HEARTS"); break;
    case 1: sprintf(suit, "SPADES"); break;
    case 2: sprintf(suit, "CLUBS"); break;
    case 3: sprintf(suit, "DIAMONDS"); break;
  }

  sprintf(OUT, "%s of %s", number, suit);
  printf("%-18s", OUT );
}


void printPlayerHand( hand* PLAYERS, int PLAYER_COUNT){
  int i, j;
  for(i = 0; i < PLAYER_COUNT; i++){
    printf("PLAYER %-11d ", i);
    
    if( i % 4 == 3 ){
      putchar('\n');
      for ( j = i-3; j < i; j++ ){
        interpretCard(PLAYERS[j].c1);
      }
      putchar('\n');
      for ( j = i-3; j < i; j++ ){
        interpretCard(PLAYERS[j].c2);
      }
      putchar('\n');
    }
  }

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

  printPlayerHand(PLAYERS, PLAYER_COUNT);

  putchar('\n');
  for (int i = 0; i < 5; i++){
    TABLE[i] = drawCard(DECK);
    if(i == 0){ printf("The FLOP:\n");}
    if(i == 3){ printf("The TURN:\n");}
    if(i == 4){ printf("The RIVER:\n");}
    printf("    ");
    interpretCard(TABLE[i]);
    putchar('\n');
  }

  //interpretCard( PLAYERS[i].c1 );

  putchar('\n');

  /* FREE UP MEMORY */
  free(DECK);
  free(PLAYERS);
  free(TABLE);
  return 0;
}

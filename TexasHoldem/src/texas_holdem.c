#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


typedef struct {
  int number;
  int suit;
} card_t;

typedef struct{
  card_t c1;
  card_t c2;
} phand_t;


// This is the final hand of each player type
typedef struct{
  card_t c1;
  card_t c2;
  card_t c3;
  card_t c4;
  card_t c5;
  int HAND;
} fhand_t;

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


card_t * populateDeck( void ) {
  int i, j;
  card_t* bDECK = (card_t *)malloc(52 * sizeof(card_t));
  int* sDECK = (int *)malloc(52 * sizeof(int));

  card_t* DECK = (card_t *)malloc(52 * sizeof(card_t));

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


card_t drawCard( card_t* DECK ){
  static int i;
  card_t c = DECK[i];
  i++;
  return c;
}


void printDeck( card_t* DECK ){
  int i;
  for( i = 0; i < 52; i++){
    printf("%d, %d\n", DECK[i].number, DECK[i].suit);
  }
}


// Prints out the card_t in a standard 18 char format
void printCard( card_t C ){
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


// TODO: Make this actually work
// Have to think through the logic a bit more...
// or use NCURSES
void printPlayerHand( phand_t* PLAYERS, int PLAYER_COUNT){
  int i=1, j, tmp_pcount = PLAYER_COUNT;

  for(i = 0; tmp_pcount > 0; tmp_pcount-=4 ){
    if (tmp_pcount > 3){
      i+=3;
      for ( j = i-3; j <= i; j++){
        printf("PLAYER %-11d ", j);
      }
      putchar('\n');
      for ( j = i-3; j <= i; j++ ){
        printCard(PLAYERS[j].c1);
        putchar(' ');
      }
      putchar('\n');
      for ( j = i-3; j <= i; j++ ){
        printCard(PLAYERS[j].c2);
        putchar(' ');
      }
      putchar('\n');
    } else {
      i+= tmp_pcount%4;
      putchar('\n');
      for ( j = i - tmp_pcount%4+1; j <= i; j++){
        printf("PLAYER %-11d ", j);
      }
      putchar('\n');
      for ( j = i- tmp_pcount%4+1; j <= i; j++ ){
        printCard(PLAYERS[j].c1);
        putchar(' ');
      }
      putchar('\n');
      for ( j = i- tmp_pcount%4+1; j <= i; j++ ){
        printCard(PLAYERS[j].c2);
        putchar(' ');
      }
      putchar('\n');
    }
  }
}


void quick_sort (card_t *a, int n) {
  int i, j, p;
  card_t t;

  if (n<2){
    return;
  }

  p = a[n/2].number;
  for (i = 0, j = n - 1;; i++, j--) {
    while (a[i].number < p)
      i++;
    while (p < a[j].number)
      j--;
    if (i >= j)
      break;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  quick_sort(a, i);
  quick_sort(a + i, n - i);
}


fhand_t * high_card_check( card_t * CHECK ){
  //int i;
  quick_sort( CHECK, 7);
  //for ( i = 0; i < 7; i++){
  //}
  return CHECK;
}

fhand_t interpretHand( card_t *TABLE, phand_t *PLAYERS, int PLAYER_COUNT ){
  int i, j;
  card_t* CHECK = (card_t *)malloc(7 * sizeof(card_t));
  for (i = 0; i < PLAYER_COUNT; i++){

    // Make and populate the Hand to be checked
    for (j = 0; j < 5; j++){
      CHECK[j] = TABLE[j];
    }
    CHECK[6] = PLAYERS[i].c1;
    CHECK[7] = PLAYERS[i].c2;
    
    // Go through the list of hands and check them!
    high_card_check( CHECK );
  }
  free(CHECK);
  return;
}


int main( int argc, char * argv[]){
  int PLAYER_COUNT = 4;

  srand(time(NULL));
  if (argc > 1){
    PLAYER_COUNT = atoi(argv[1]);
  }

  card_t* DECK = populateDeck();
  phand_t* PLAYERS = (phand_t *)malloc(PLAYER_COUNT * sizeof(phand_t));
  card_t* TABLE = (card_t *)malloc(5 * sizeof(card_t));
  
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
    printCard(TABLE[i]);
    putchar('\n');
  }

  /* CHECK HANDS */
  interpretHand( TABLE, PLAYERS, PLAYER_COUNT);


  /* FREE UP MEMORY */
  free(DECK);
  free(PLAYERS);
  free(TABLE);
  putchar('\n');
  return 0;
}

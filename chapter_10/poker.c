#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SUITS 4
#define RANKS 13
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14
#define CLUBS 0
#define SPADES 1
#define HEARTS 2
#define DIAMONDS 3
#define HAND 5
#define CLASS 9
#define FOUR_KIND 5
#define FULL_HOUSE 4
#define THREE_KIND 3
#define TWO_PAIR 2
#define PAIR 1

/********************************************************
* Deal will distribute 5 unique cards to the users hand *
********************************************************/ 
void deal(int deck[][RANKS], int hand[HAND][2]);

/********************************************************
* Classify takes a dealt hand and provides a rank based *
* on the contents and a pre-determined class system     *
********************************************************/ 
int classify(int hand[HAND][2]);

/********************************************************
* 'Shuffles' the deck, generates a new random key and   *
* announces the shuffle is occurring                    *
********************************************************/ 
void shuffle_deck(void);

/********************************************************
* Takes the hand and reads out the values to the user   *
********************************************************/ 
void read_hand(int hand[HAND][2]);

/********************************************************
* Checks for a straight                                 *
********************************************************/ 
bool check_straight(int hand[HAND][2]);

/********************************************************
* Checks for a flush                                    *
********************************************************/ 
bool check_flush(int hand[HAND][2]);

/********************************************************
* Checks for pairs                                      *
********************************************************/ 
int check_kind(int hand[HAND][2]);

/********************************************************
* Sorts the hand                                        *
********************************************************/ 
void selection_sort(int a[][2], int n);

int main(int argc, char *argv[])
{
  int hand[HAND][2] = {0};
  int deck[SUITS][RANKS] = {
    {2, 3, 4, 5, 6, 7, 8, 9, 10, JACK, QUEEN, KING, ACE},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, JACK, QUEEN, KING, ACE},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, JACK, QUEEN, KING, ACE},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, JACK, QUEEN, KING, ACE}
  };
  
  shuffle_deck();
  deal(deck, hand);
  read_hand(hand);
  classify(hand);

  return EXIT_SUCCESS;
}

void deal(int deck[][RANKS], int hand[][2]){
  int suit = 0, rank = 0;
  for (int i = 0; i < HAND; i++){
    
    do {
      suit = rand() % SUITS;
      rank = 2 + rand() % (RANKS - 2);
    } while (deck[suit][rank] == 0); 
    
    hand[i][1] = suit;
    hand[i][0] = rank;
    deck[suit][rank] = 0;
  }
  selection_sort(hand, HAND);
}

int classify(int hand[][2]){
  int class = 0, kind = 0;
  bool straight, flush;

  straight = check_straight(hand);
  flush = check_flush(hand);
  kind = check_kind(hand);
  printf("\n");
  if (straight && flush && hand[0][0] == 10)
    printf("Royal Flush!!!!\n");
  else if(straight && flush) 
    printf("Straight Flush!\n");
  else if(kind == FOUR_KIND) 
    printf("Four of a Kind!\n");
  else if(kind == FULL_HOUSE)
    printf("Full House!\n");
  else if(straight)
    printf("Straight!\n");
  else if(kind == THREE_KIND)
    printf("Three of a Kind!\n");
  else if(kind == TWO_PAIR)
    printf("Two Pair!\n");
  else if(kind == PAIR)
    printf("Pair!\n");
  else
    printf("Nothing!\n");
  
  return class;
}

bool check_straight(int hand[][2]){
  int step = -1;
  if (hand[1][0] - hand[0][0] > 0)
    step = 1;
  
  for (int i = 1; i < HAND; i++){
    if (hand[i][0] - hand[i-1][0] != step)
      return false;
  }
  return true;
}

bool check_flush(int hand[][2]){
  int suit = hand[0][1];
  for (int i = 1; i < HAND; i++){
    if (hand[i][1] != suit)
      return false;
  }
  return true;
}

int check_kind(int hand[][2]){
  int pair_count = 0;
  bool three = false;
  int ranks[RANKS] = {0};

  for (int i = 0; i < HAND; i++){
    ranks[hand[i][0]]++;
  }

  for (int i = 0; i < RANKS; i++){
    if (ranks[i] == 4) return FOUR_KIND;
    if (ranks[i] == 3) three = true;
    if (ranks[i] == 2) pair_count++;
  }

  if (pair_count == 1 && three) return FULL_HOUSE;
  if (three) return THREE_KIND;
  if (pair_count == 2) return TWO_PAIR;
  if (pair_count == 1) return PAIR;
  return 0;
}


void shuffle_deck(void){
  srand((unsigned) time(NULL));
  printf("Shuffling the deck!\n\n");
}

void read_hand(int hand[][2]){
  for (int i = 0; i < HAND; i++){
    switch(hand[i][0]){
      case 2: printf("Two of ");
      break;
      case 3: printf("Three of ");
      break;
      case 4: printf("Four of ");
      break;
      case 5: printf("Five of ");
      break;
      case 6: printf("Six of ");
      break;
      case 7: printf("Seven of ");
      break;
      case 8: printf("Eight of ");
      break;
      case 9: printf("Nine of ");
      break;
      case 10: printf("Ten of ");
      break;
      case JACK: printf("Jack of ");
      break;
      case QUEEN: printf("Queen of ");
      break;
      case KING: printf("King of ");
      break;
      case ACE: printf("Ace of ");
      break;
    }
    switch(hand[i][1]){
      case CLUBS: printf("Clubs\n");
      break;
      case SPADES: printf("Spades\n");
      break;
      case HEARTS: printf("Hearts\n");
      break;
      case DIAMONDS: printf("Diamonds\n");
      break;
    }
  }
}

void selection_sort(int a[][2], int n){
  int i, temp_rank, temp_suit, max_position, max_rank = 0, max_suit = 0;
  if (n > 1) {
    for (i = 0; i < n; i++){
      if (a[i][0] > max_rank) {
        max_rank = a[i][0];
        max_suit = a[i][1];
        max_position = i;
      }
    }
    
    temp_rank = a[n-1][0];
    temp_suit = a[n-1][1];
    a[n-1][0] = max_rank;
    a[n-1][1] = max_suit;
    a[max_position][0] = temp_rank;
    a[max_position][1] = temp_suit;

    selection_sort(a, n-1);
  }
}

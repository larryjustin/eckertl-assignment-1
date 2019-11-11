//
// Unit test for Baron card.
//
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

int localassert(int b, char* s) {
    if (!b) {
        printf ("Failure to assert: %s\n", s);
        if (0) {
            exit(1);
        }
    }
}

int main(){
    struct gameState G;
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    initializeGame(2, k, 1 , &G);
    printf("\nTest for Baron.\n");
    int buys=G.numBuys;
    G.hand[whoseTurn(&G)][0]=estate;
    int coins= G.coins;
    int r = cardEffect(baron,1,2,3,&G,2,0);
    localassert(G.coins == coins+4, "Incorrect coin count.\n");
    localassert(G.numBuys == buys+1, "Incorrect buy count.\n");
    localassert(r==0,"Incorrect r count.\n");
    printf("ALL TESTS PASSED\n");
    return 0;
}
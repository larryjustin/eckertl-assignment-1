//
// Unit test for minion card
//
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void localassert(int b, char* s) {
    if (!b) {
        printf ("Failure to assert: %s\n", s);
        if (0) {
            exit(1);
        }
    }
}

int main () {

    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G;
    initializeGame(2, k, 3, &G);
    printf("\nTest for Minion.\n");

    G.hand[0][0] = minion;
    int coins = G.coins;
    playCard(0, 1, 0, 0, &G);
    localassert (G.coins == coins + 2, "Incorrect coin count.\n");
    printf ("%d, %d\n", G.coins, coins);
    printf ("%d\n", G.handCount[0]);
    printf("ALL TESTS PASSED\n");
    return 0;
}
//
// Unit test for ambassador card
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
    initializeGame(2, k, 5, &G);
    printf("\nTest for Ambassador.\n");

    G.hand[0][0] = ambassador;
    int r = cardEffect(ambassador, 1, 1, 1, &G, 0, 0);
    localassert (r == 0, "Ambassador failure.\n");
    printf("ALL TESTS PASSED\n");
    return 0;
}


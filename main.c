#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main(void){
    bool gameFinished = false;
    int emplacementLeft = 42;
    int currentPlayerPlaying = 0;

    while (!gameFinished && emplacementLeft > 0){
        printf("Next round\n");
        printf("Player %d is playing \n", currentPlayerPlaying);
        emplacementLeft -= 1;
        currentPlayerPlaying = currentPlayerPlaying == 0 && 1 || 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void main(void){
    bool gameFinished = false;
    int emplacementLeft = 42;
    int currentPlayerPlaying = 0;

    //PLAYER'S NAMES SELECTION
    char playerOne[15], playerTwo[15];
    for (;;) //Infinite loop without condition to enter
        {
            printf("%s","Player1, please select your name: ");
            scanf("%s", playerOne);
            printf("%s","Player2, please select your name: ");
            scanf("%s", playerTwo);
            if (strlen(playerOne) < 15 &&  strlen(playerTwo) < 15) break; // Check if names have < 15 characters
            printf( "Please enter a name under 15 characters.\n" );
        }      

    while (!gameFinished && emplacementLeft > 0){
        
        //Check and select player's name, depending of the turn
        if (currentPlayerPlaying) {
            printf("%s is playing \n", playerOne);
        }
        else {
            printf("%s is playing \n", playerTwo);
        }

        printf("Next round\n");
        emplacementLeft -= 1;
        currentPlayerPlaying = currentPlayerPlaying ^ 1;
    }
}
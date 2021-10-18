#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define gridX 6
#define gridY 7

char gameGrid[gridX][gridY];
char tokens[] = "ox";

void repeatStr(char str[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", str);
    }
    printf("\n");
}

void printGrid() {
    repeatStr("__", gridY);

    for(int x = 0; x<gridX;x++){
        for(int y = 0; y < gridY; y++){
            printf("%c ", gameGrid[x][y]);
        }
        printf("\n");
    }

    repeatStr("__", gridY);
}

int placeSymbol(x,symbol) {
    if (x > gridX){
        return 2; // out of range
    }else if(gameGrid[0][x] != '.'){
        return 0; // full
    }else{
        for (int i = gridX; i >= 0; i--){
            if (gameGrid[i][x] == '.'){
                gameGrid[i][x] = symbol; // setting symbol
                break;
            }
        }
    }
    return 1;
}

void init(void) {
    for(int x = 0; x<gridX;x++){
        for(int y = 0; y < gridY; y++){
            gameGrid[x][y] = '.';
        }
    }
}


int main(void){
    bool gameFinished = false;
    int emplacementLeft = 42;
    int currentPlayerPlaying = 0;

    init();
    //PLAYER NAME SELECTION
    int value;
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
        printGrid();
        if (currentPlayerPlaying) {
            printf("%s is playing \n", playerOne);
        }
        else {
            printf("%s is playing \n", playerTwo);
        }

        for (;;){
            printf("%s %i %s","Please select a column between 0 and",gridY," : ");
            scanf("%d", &value);
            if (value > 7 || value < 1) printf("Please enter a true value\n");
            else {
                placeSymbol(value-1,tokens[currentPlayerPlaying]);
                break;
            }
        }
        printf("Next round\n");
        emplacementLeft -= 1;
        currentPlayerPlaying = currentPlayerPlaying ^ 1;
    }

    return 1;
}

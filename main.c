#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define gridY 7
#define gridX 6

char gameGrid[gridX][gridY];

void repeatStr(char str[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%c", *str);
    }
    printf("\n");
}

void printGrid() {
    repeatStr("_", gridY);

    for(int x = 0; x<gridX;x++){
        for(int y = 0; y < gridY; y++){
            printf("%c", gameGrid[x][y]);
        }
        printf("\n");
    }
    
    repeatStr("_", gridY);
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

    while (!gameFinished && emplacementLeft > 0){
        //printf("Next round\n");
        //printf("Player %d is playing \n", currentPlayerPlaying);
        emplacementLeft -= 1;
        currentPlayerPlaying = currentPlayerPlaying ^ 1;
    }
    printGrid();

    return 1;
}
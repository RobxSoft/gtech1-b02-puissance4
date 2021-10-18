#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define gridY 7
#define gridX 6

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
    printGrid();
    while (!gameFinished && emplacementLeft > 0){
        //printf("Next round\n");
        //printf("Player %d is playing \n", currentPlayerPlaying);
        emplacementLeft -= 1;
        currentPlayerPlaying = currentPlayerPlaying ^ 1;
        printf("playing : %c\n", tokens[currentPlayerPlaying]);
        placeSymbol(1,tokens[currentPlayerPlaying]);
        printGrid();
    }
    int test;
    if (sscanf("%d", &test) == 1){
        printf("Nice");
    }

    return 1;
}
#include "../Headers/Winner.h"
#include "../Headers/glob.h"
extern char gameGrid[gridX][gridY];

int leftRight(int x, int y, int placedY, char lookingTo){
    if (y != placedY && lookingTo == gameGrid[x][y]){
        return 1; // Same symbol, incrementing combo
    }else if(gameGrid[x][y] != lookingTo){
        return 0; // Symbol was different from the player symbol (x != o)
    }
}

int topBottom(int x, int y, int placedX, char lookingTo){
    if (x != placedX && lookingTo == gameGrid[x][y]){
        return 1; // Same symbol, incrementing combo
    }else if(gameGrid[x][y] != lookingTo){
        return 0; // Symbol was different from the player symbol (x != o)
    }
}

bool Winner(int placedY,int placedX){
    char lookingTo = gameGrid[placedX][placedY];
    int currentCombo = 0;

    for(int y = placedY; y < gridY; y++){ // Looking if player won (right)
        int result = leftRight(placedX,y,placedY,lookingTo);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo == 4){
                return true;
            }
        }else if(result == 0) break;
    }

    currentCombo = 0;

    for(int y = placedY; y> 0; y--){ // Looking if player won (left)
        int result = leftRight(placedX,y,placedY,lookingTo);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo == 4){
                return true;
            }
        }else if(result == 0) break;
    }
    currentCombo = 0;

    for(int x = placedX; x> 0; x++){ // Looking if player won (top)
        int result = topBottom(x,placedY,placedX,lookingTo);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo == 4){
                return true;
            }
        }else if(result == 0) break;
    }
    currentCombo = 0;

    if(placedX > gridX-4){
        if(placedY+4<=gridY){ // right top dia
            for(int x = placedX; x>0;x--){
                if (lookingTo == gameGrid[x][placedY+(1*(placedX-x))]) {
                    currentCombo += 1;
                    if (currentCombo == 4){
                        return true;
                    }
                }else break;
            }
        }

        currentCombo = 0;

        if(placedY-4>=0){ // left top dia
            for(int x = placedX; x>0;x--){
                if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
                    currentCombo += 1;
                    if (currentCombo == 4){
                        return true;
                    }
                }else break;
            }
        }
    }

    currentCombo = 0;

    if(placedX+4 <= gridX){
        if(placedY+4<=gridY){ // right bottom dia
        printf("Right bottom dia\n");
            for(int x = placedX; x<gridX;x++){
                printf("x : %d\n", x);
                printf("y : %d\n", placedY+(1*(x-placedX)));
                printf("Looking at : %c\n", gameGrid[x][placedY+(1*(x-placedX))]);
                if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
                    currentCombo += 1;
                    printf("New combo : %d\n", currentCombo);
                    if (currentCombo == 4){
                        return true;
                    }
                }else break;
            }
        }

        currentCombo = 0;

        if(placedY-4>=0){ // left bottom dia
            for(int x = placedX; x<gridX;x++){
                if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
                    currentCombo += 1;
                    if (currentCombo == 4){
                        return true;
                    }
                }else break;
            }
        }
    }

    currentCombo = 0;

    return false;
}
#include "../Headers/Winner.h"
#include "../Headers/glob.h"
//extern char gameGrid[gridX][gridY];

int leftRight(int x, int y, int placedY, char lookingTo, char **gameGrid){
    if (y != placedY && lookingTo == gameGrid[x][y]){
        return 1; // Same symbol, incrementing combo
    }else if(gameGrid[x][y] != lookingTo){
        return 0; // Symbol was different from the player symbol (x != o)
    }else{
        return -1; // y = placed Y
    }
}

int topBottom(int x, int y, int placedX, char lookingTo, char **gameGrid){
    if (x != placedX && lookingTo == gameGrid[x][y]){
        return 1; // Same symbol, incrementing combo
    }else if(gameGrid[x][y] != lookingTo){
        return 0; // Symbol was different from the player symbol (x != o)
    }else{
        return -1; // y = placed Y
    }
}

bool Winner(int placedY, int placedX, char **gameGrid, int gridX, int gridY){
    char lookingTo = gameGrid[placedX][placedY];
    int currentCombo = 1; // Set to 1 bc we're iterating after the placed value
    for(int y = placedY; y < gridY; y++){ // Looking if player won (right)
        int result = leftRight(placedX,y,placedY,lookingTo,gameGrid);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else if(result == 0) break;
    }

    for(int y = placedY; y >= 0; y--){ // Looking if player won (left)
        int result = leftRight(placedX,y,placedY,lookingTo,gameGrid);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else if(result == 0) break;
    }
    currentCombo = 1; // Set to 1 bc we're iterating after the placed value

    for(int x = placedX; x < gridX; x++){ // Looking if player won (top)
        int result = topBottom(x,placedY,placedX,lookingTo,gameGrid);
        
        if (result == 1){
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else if(result == 0) break;
    }
    currentCombo = 0; // Set to 0 bc we're iterating on the diagonal and it also increment on the placed symbol

    for(int x = placedX; x>0;x--){ //DIAGONAL CHECK
        if (lookingTo == gameGrid[x][placedY+(1*(placedX-x))]) {
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else break;
    }
    currentCombo -= 1; // preventing to count 2 time the placed symbol

    for(int x = placedX; x<gridX;x++){ //DIAGONAL CHECK
        if (lookingTo == gameGrid[x][placedY+(1*(placedX-x))]) {
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else break;
    }

    currentCombo = 0;

    for(int x = placedX; x>0;x--){ //DIAGONAL CHECK
        if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else break;
    }

    currentCombo -= 1; // preventing to count 2 time the placed symbol

    for(int x = placedX; x<gridX;x++){ //DIAGONAL CHECK

        if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else break;
    }

    currentCombo = 0;

    return false;
}
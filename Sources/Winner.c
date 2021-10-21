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
    int currentCombo = 1; // Set to 1 bc we're iterating after the placed value

    printf("Looking right\n");
    for(int y = placedY; y < gridY; y++){ // Looking if player won (right)
        int result = leftRight(placedX,y,placedY,lookingTo);
        printf("right result : %d\n", result);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else if(result == 0) break;
    }

    printf("Looking left\n");
    for(int y = placedY; y >= 0; y--){ // Looking if player won (left)
        int result = leftRight(placedX,y,placedY,lookingTo);
        printf("left y : %d", y);
        printf("left result : %d\n", result);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else if(result == 0) break;
    }
    currentCombo = 1; // Set to 1 bc we're iterating after the placed value

    printf("Looking top\n");
    for(int x = placedX; x> 0; x++){ // Looking if player won (top)
        int result = topBottom(x,placedY,placedX,lookingTo);
        printf("top result : %d\n", result);
        if (result == 1){
            currentCombo += 1;
            if (currentCombo >= 4){
                return true;
            }
        }else if(result == 0) break;
    }
    currentCombo = 0; // Set to 0 bc we're iterating on the diagonal and it also increment on the placed symbol

    //if(placedY+4<=gridY){ // right top dia
    printf("right top dia\n");
        for(int x = placedX; x>0;x--){
            printf("Looking on (%d/%d) for right top dia so : %c\n", x, placedY+(1*(placedX-x)), gameGrid[x][placedY+(1*(placedX-x))]);
            if (lookingTo == gameGrid[x][placedY+(1*(placedX-x))]) {
                currentCombo += 1;
                if (currentCombo >= 4){
                    return true;
                }
            }else break;
        }
    //}

    currentCombo -= 1; // preventing to count 2 time the placed symbol

    //if(placedY-4>=0){ // left bottom dia
        printf("left bottom dia\n");
        for(int x = placedX; x<gridX;x++){
            printf("Looking on (%d/%d) for left bottom dia so : %c\n", x, placedY+(1*(x-placedX)), gameGrid[x][placedY+(1*(placedX-x))]);
            if (lookingTo == gameGrid[x][placedY+(1*(placedX-x))]) {
                currentCombo += 1;
                if (currentCombo >= 4){
                    return true;
                }
            }else break;
        }
    //}

    currentCombo = 0;

    //if(placedY-4>=0){ // left top dia
        printf("Left top dia\n");
        for(int x = placedX; x>0;x--){
            printf("Looking on (%d/%d) for left top dia so : %c\n", x, placedY+(1*(x-placedX)), gameGrid[x][placedY+(1*(x-placedX))]);
            if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
                currentCombo += 1;
                if (currentCombo >= 4){
                    return true;
                }
            }else break;
        }
    //}

    currentCombo -= 1; // preventing to count 2 time the placed symbol

    //if(placedY+4<=gridY){ // right bottom dia
        printf("Right bottom dia\n");
        for(int x = placedX; x<gridX;x++){
            printf("Looking on (%d/%d) for right bottom dia so : %c\n", x, placedY+(1*(x-placedX)), gameGrid[x][placedY+(1*(x-placedX))]);
            // printf("x : %d\n", x);
            // printf("y : %d\n", placedY+(1*(x-placedX)));
            // printf("Looking at : %c\n", gameGrid[x][placedY+(1*(x-placedX))]);
            if (lookingTo == gameGrid[x][placedY+(1*(x-placedX))]) {
                currentCombo += 1;
                printf("New combo : %d\n", currentCombo);
                if (currentCombo >= 4){
                    return true;
                }
            }else break;
        }
    //}

    currentCombo = 0;

    return false;
}
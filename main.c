#include "Headers/Winner.h"
#include "Headers/glob.h"

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

void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF){}
}


int main(void){
    bool gameFinished = false;
    int emplacementLeft = 42;
    int currentPlayerPlaying = 0;

    init();

    //MAIN MENU
    printf("%s %s %s %s %s %s %s %s","\033[0;35m","\n ▒█▀▀█ ▒█░▒█ ▀█▀ ▒█▀▀▀█ ▒█▀▀▀█ ░█▀▀█ ▒█▄░▒█ ▒█▀▀█ ▒█▀▀▀    ░█▀█░\n",
    "▒█▄▄█ ▒█░▒█ ▒█░ ░▀▀▀▄▄ ░▀▀▀▄▄ ▒█▄▄█ ▒█▒█▒█ ▒█░░░ ▒█▀▀▀    █▄▄█▄\n",
    "▒█░░░ ░▀▄▄▀ ▄█▄ ▒█▄▄▄█ ▒█▄▄▄█ ▒█░▒█ ▒█░░▀█ ▒█▄▄█ ▒█▄▄▄    ░░░█░\n\n","\033[0;36m"," => align 4 tokens and win !","\033[0;37m","\n\nPress any key ton continue...");
    getchar();
    
    

    //PLAYER NAME SELECTION
    char playerOne[15], playerTwo[15];
    for (;;) //Infinite loop without condition to enter
        {
            printf("%s %s %s %s","\x1b[33m","\n\nPlayer1,","\033[0;37m","please select your name: ");
            scanf("%s",playerOne);
            printf("%s %s %s %s","\033[0;31m","\n\nPlayer2,","\033[0;37m","please select your name: ");
            scanf("%s", playerTwo);
            if (strlen(playerOne) < 15 &&  strlen(playerTwo) < 15) break; // Check if names have < 15 characters
            printf( "Please enter a name under 15 characters.\n" );
        }

    while (!gameFinished && emplacementLeft > 0){

        //Check and select player's name, depending of the turn
        if (currentPlayerPlaying) {
            printf("%s %s %s","\n\x1b[33m ●",playerOne,"is playing\033[0;37m\n");
        }
        else {
            printf("%s %s %s","\n\033[0;31m ●",playerTwo,"is playing\033[0;37m\n");
        }

        printGrid();

        for (;;){
            int value;
            printf("%s %i %s","Please select a column between 1 and",gridY," :");
            scanf("%d", &value);
            if (value > 7 || value < 1 || placeSymbol(value-1,tokens[currentPlayerPlaying]) == 0) {
                printf("Please enter a true number\n");
                flushstdin();
            }
            else {
                break;
            }
        }
        Winner();
        printf("\033[0;34m\n\n█▄░█ █▀▀ ▀▄▀ ▀█▀   █▀█ █▀█ █░█ █▄░█ █▀▄\n█░▀█ ██▄ █░█ ░█░   █▀▄ █▄█ █▄█ █░▀█ █▄▀\033[0;37m\n\n");
        emplacementLeft -= 1;
        currentPlayerPlaying = currentPlayerPlaying ^ 1;
    }

    return 1;
}

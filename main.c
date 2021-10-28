#include "Headers/Winner.h"
#include "Headers/glob.h"

char tokens[] = "ox";

void repeatStr(char str[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", str);
    }
    printf("\n");
}

void printGrid(char **gameGrid, int gridX, int gridY) {
    repeatStr("__", gridY);

    for(int x = 0; x<gridX;x++){
        for(int y = 0; y < gridY; y++){
            printf("%c ", gameGrid[x][y]);
        }
        printf("\n");
    }
    
    for(int y = 0; y < gridY; y++){
        printf("%d ", y+1);
    }
    printf("\n");

    repeatStr("__", gridY);
}

int placeSymbol(int x, char symbol,char **gameGrid, int gridX, int gridY) {
    printf("");
    if (x > gridY || x < 1 ) return -4;
    x = x - 1;
    if (x > gridX){
        return -2; // out of range
    }else if(gameGrid[0][x] != '.'){
        return -3; // full
    }else{
        for (int i = gridX-1; i >= 0; i--){
            if (gameGrid[i][x] == '.'){
                gameGrid[i][x] = symbol; // setting symbol
                return i;
            }
        }
    }
    return -1;
}

void init(char **gameGrid, int gridX, int gridY) {
    for(int x = 0; x<gridX;x++){
        gameGrid[x] = (char *)malloc(gridX * sizeof(char));
        for(int y = 0; y < gridY; y++){
            gameGrid[x][y] = '.';
        }
    }
}

void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF){}
}

int customIntInput(char *question, int min){ //custom int input function that won't stop until the user enter a number which is > to min.
    int value;
    for(;;){
        printf("%s", question);
        if (scanf("%d", &value) == 0){
                printf("\nPlease enter a right type of number.\n");
                flushstdin();
        }else{
            if(value<=min){
                printf("\nPlease enter a right type of number.\n");
                flushstdin();
            }else{
                break;
            }
        }
    }
    return value;
}

int main(void){
    bool gameFinished = false;
    int currentPlayerPlaying = 0;

     //MAIN MENU
    printf("%s %s %s %s %s %s %s","\033[0;35m","\n ▒█▀▀█ ▒█░▒█ ▀█▀ ▒█▀▀▀█ ▒█▀▀▀█ ░█▀▀█ ▒█▄░▒█ ▒█▀▀█ ▒█▀▀▀    ░█▀█░\n",
    "▒█▄▄█ ▒█░▒█ ▒█░ ░▀▀▀▄▄ ░▀▀▀▄▄ ▒█▄▄█ ▒█▒█▒█ ▒█░░░ ▒█▀▀▀    █▄▄█▄\n",
    "▒█░░░ ░▀▄▄▀ ▄█▄ ▒█▄▄▄█ ▒█▄▄▄█ ▒█░▒█ ▒█░░▀█ ▒█▄▄█ ▒█▄▄▄    ░░░█░\n\n","\033[0;36m"," => align 4 tokens and win !","\033[0;37m\n\n");

    //Custom Grid
    printf("Grid Customisation : \n\n");
    int gridX = customIntInput("Enter the amount of row you want to play with (Basic Game : 6) : ",3);
    flushstdin();
    int gridY = customIntInput("Enter the amount of column you want to play with (Basic Game : 7x) : ",3);

    int emplacementLeft = gridX*gridY;
    char **gameGrid = (char **)malloc((gridY) * sizeof(char *)); // generating game grid array

    init(gameGrid, gridX, gridY);
    
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

        printGrid(gameGrid, gridX, gridY);
        
        int value, yValue;
        for (;;){
            flushstdin();
            printf("%s %i %s","Please select a column between 1 and",gridY," :");
            if (scanf("%d", &value) == 0){
                printf("\nPlease enter a right type of number.\n");
            }else{
                yValue = placeSymbol(value,tokens[currentPlayerPlaying],gameGrid,gridX,gridY);
                if (yValue < -1) {
                    printf("Please enter a right type of number.\n");
                }
                else {
                    break;
                }
            }
        }
        if (Winner(value-1, yValue, gameGrid, gridX, gridY) == true) {
            printGrid(gameGrid, gridX, gridY);
            if (currentPlayerPlaying) {
                printf("%s %s %s","\n\x1b[33m",playerOne,"IS THE WINNER !\033[0;37m\n");
            }
            else {
                printf("%s %s %s","\n\033[0;31m",playerTwo,"IS THE WINNER !\033[0;37m\n");
            }
            gameFinished = true;
        }
        emplacementLeft -= 1;
        if(gameFinished == false && emplacementLeft > 0){
            printf("\033[0;34m\n\n█▄░█ █▀▀ ▀▄▀ ▀█▀   █▀█ █▀█ █░█ █▄░█ █▀▄\n█░▀█ ██▄ █░█ ░█░   █▀▄ █▄█ █▄█ █░▀█ █▄▀\033[0;37m\n\n");
        }else if(emplacementLeft == 0){
            printGrid(gameGrid, gridX, gridY);
            printf("No more emplacement left, no one won this game.\n");
        }
        currentPlayerPlaying = currentPlayerPlaying ^ 1;
    }
    free(gameGrid);
    return 1;
}

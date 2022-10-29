/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Lorenz Alvin Tubo
Student ID#: 109934224
Email      : lorenzalvintubo@gmail.com or ltubo@myseneca.ca
Section    : IPC144NKK

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#define MAXLENGTH 70
#define MINLENGTH 10
#define MULTIPLE 5
#define MINPATH 1

    struct PlayerInfo{
        int numLife;
        char playerName;
        int counterTreasure;
        char pathHistory[MAXLENGTH];
        int path;
    };
    struct GameInfo{
        int maxMoves;
        int pathLength;
        int bombs[MAXLENGTH];
        int treasure[MAXLENGTH];
        char major[MAXLENGTH];
        int minor[MAXLENGTH];
    };
int main(void)
{   
    struct GameInfo game;
    struct PlayerInfo player;
    int exit = 0;
    int i, j, k, begin, end = MULTIPLE;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");

    printf("\nPLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerName);
    do{
    printf("Set the number of lives: ");
    scanf(" %d", &player.numLife);
        if ((player.numLife == 0) || (player.numLife > MINLENGTH))
        {
            printf("     Must be between 1 and 10!\n");  
        }
        else if((player.numLife > 0) && (player.numLife < MINLENGTH))
        {
            exit = 1;
        }
    }while (exit == 0);
    exit = 0;
    printf("Player configuration set-up is complete\n");

    printf("\nGAME Configuration\n");
    printf("------------------\n");
    do{
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MINLENGTH, MAXLENGTH);
        scanf(" %d", &game.pathLength);
        if ((game.pathLength < MINLENGTH) || (game.pathLength > MAXLENGTH) || (game.pathLength % MULTIPLE != 0))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MINLENGTH, MAXLENGTH);
        }
        else if ((game.pathLength >= MINLENGTH) && (game.pathLength <= MAXLENGTH) && (game.pathLength % MULTIPLE == 0))
        {
            exit = 1;
        }
        
    }while (exit == 0);
    exit = 0;
    do{
        printf("Set the limit for number of moves allowed: ");
        scanf(" %d", &game.maxMoves);
        if((game.maxMoves < player.numLife) || (game.maxMoves > (game.pathLength * .75) + .5))
        {
            printf("    Value must be between %d and %d\n", player.numLife, (int)((game.pathLength * .75)+ .5));
        }
        else if ((game.maxMoves >=3) && (game.maxMoves <= 26))
        {
            exit = 1;
        }
    }while (exit == 0);

    printf("\nBOMB Placement\n");
    printf("--------------");
    printf("\nEnter the bomb positions in sets of %d where a value", MULTIPLE);
    printf("\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    int loopControl = game.pathLength/MULTIPLE;
    j = 0;
    for(i= 0; i < loopControl; i++)
    {
        if ((begin < 10) && (end < 10))
        {
        printf("   Positions [ %d- %d]: ", begin + 1, end);
        }
        else if (begin < 10)
        {
        printf("   Positions [ %d-%d]: ", begin + 1, end);
        }
        else
        {
            printf("   Positions [%d-%d]: ", begin + 1, end);
        }
        for (k = 0; k < MULTIPLE; k++){
            scanf(" %d", &game.bombs[j]);
            j++;
        }
        begin += MULTIPLE;
        end += MULTIPLE;
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------");
    printf("\nEnter the treasure placements in sets of %d where a value", MULTIPLE);
    printf("\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
    printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    end = MULTIPLE;
    begin = 0;
    j = 0;
    for(i= 0; i < loopControl; i++)
    {
        if (begin < 10 && end < 10)
        {
        printf("   Positions [ %d- %d]: ", begin + 1, end);
        }
        else if (begin < 10)
        {
        printf("   Positions [ %d-%d]: ", begin + 1, end);
        }
        else 
        {
            printf("   Positions [%d-%d]: ", begin + 1, end);
        }
        for (k = 0; k < MULTIPLE; k++)
        {
            scanf("%d", &game.treasure[j]);
            j++;
        }
        begin += MULTIPLE;
        end += MULTIPLE;
    }
    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n");
    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c", player.playerName);
    printf("\n   Lives      : %d", player.numLife);
    printf("\n   Treasure   : [ready for gameplay]");
    printf("\n   History    : [ready for gameplay]\n");

    printf("\nGame:\n");
    printf("   Path Length: %d", game.pathLength);
    printf("\n   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]);
    }
printf("\n\n====================================\n");
printf("~ Get ready to play TREASURE HUNT! ~\n");
printf("====================================\n");
exit = 0;
k =0; 
    for (i = 0; i < game.pathLength; i++){
    player.pathHistory[i] = '-';
    game.major[i] = '|';
    if(i > 8)
    {
        game.minor[i] = k;
        k++;
    }
    else {
        game.minor[i] = i + 1;
    }
    if (k > 9){
        k = 0;
    }
    }
player.counterTreasure = 0;
    printf("\n  ");
for (i = 0; i < game.pathLength; i++){
    printf("%c", player.pathHistory[i]);
}
printf("\n  ");
k = 1;
for (i = 0; i < game.pathLength; i++){
    if (game.minor[i]== 0){
        printf("%d", k);
        k++;
    }
    else {
         printf("%c", game.major[i]);
    }
    }

printf("\n  ");
for (i = 0; i < game.pathLength; i++){
    printf("%d", game.minor[i]);
}
printf ("\n+---------------------------------------------------+\n");
printf ("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d", player.numLife, player.counterTreasure, game.maxMoves);
printf ("\n+---------------------------------------------------+");
do{
do{
printf("\nNext Move [%d-%d]: ", MINPATH, game.pathLength);
scanf("%d", &player.path);
if (player.path > game.pathLength || player.path < MINPATH){
    printf("  Out of Range!!!");
}
}while (player.path > game.pathLength || player.path < MINPATH);
player.path = player.path -1;
if (player.pathHistory[player.path] != '-'){
    printf("\n===============> Dope! You've been here before!\n");
}
if (game.bombs[player.path] == 0 && game.treasure[player.path]== 0 && player.pathHistory[player.path] == '-'){
    printf("\n===============> [.] ...Nothing found here... [.]\n");
    player.pathHistory[player.path] = '.';
    game.maxMoves--;
}
if (game.bombs[player.path] == 1 && game.treasure[player.path] == 0 && player.pathHistory[player.path] == '-'){
    printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
    player.pathHistory[player.path] = '!';
    player.numLife--;
    game.maxMoves--;

}
if (game.bombs[player.path] == 0 && game.treasure[player.path] == 1 && player.pathHistory[player.path] == '-'){
    printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
    player.pathHistory[player.path] = '$';
    player.counterTreasure++;
    game.maxMoves--;
}
if (game.bombs[player.path] == 1 && game.treasure[player.path] == 1 && player.pathHistory[player.path] == '-'){
     printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
    player.pathHistory[player.path] = '&';
    player.counterTreasure++;
    game.maxMoves--;
    player.numLife--;
}
if (player.numLife == 0 || game.maxMoves == 0){
    printf("\nNo more LIVES remaining!\n");
    exit = 1;
}
printf("\n");
for (i = 0; i < player.path; i++ ){
    printf(" ");
}
printf("  %c", player.playerName);
    printf("\n  ");
for (i = 0; i < game.pathLength; i++){
    printf("%c", player.pathHistory[i]);
}
printf("\n  ");
k = 1;
for (i = 0; i < game.pathLength; i++){
    if (game.minor[i]== 0){
        printf("%d", k);
        k++;
    }
    else {
         printf("%c", game.major[i]);
    }
    }

printf("\n  ");
for (i = 0; i < game.pathLength; i++){
    printf("%d", game.minor[i]);
}
printf ("\n+---------------------------------------------------+\n");
printf ("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d", player.numLife, player.counterTreasure, game.maxMoves);
printf ("\n+---------------------------------------------------+");
}while (exit == 0);
printf("\n\n##################\n");
printf("#   Game over!   #\n");
printf("##################\n");
printf("\nYou should play again and try to beat your score!\n");
return 0;
}
//hello3.c
//Something something hello there
//General Kenobi

//This is a simple CLI program. Next steps might be multi-file before then going on to API programming.
//Need to find some kind of lorem ipsum core code to do things like this with

//opensource.com - How to write a good C main function
//According to somebody on the internet I should structure a C program roughly like this:
//-#includes
//-#defines
//-external declarations
//-typedefs
//-global variable declarations
//-function prototypes
//int main(int argc, char* argv[]){ --validate inouts
//int usage(){
//everything else

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*
#define OPTSTR "vi:o:f:h"
#define USAGE_FMT "%s [-v] [-f hexflag] [-i inputfile] [-o outputfile] [-h]"
#define ERR_FOPEN_INPUT "fopen(input, r)"
#define ERR_FOPEN_OUTPUT "fopen(output, w)"
#define ERR_DO_THE_NEEDFUL "do_the_needful blew up"
#define DEFAULT_PROGNAME "george"
*/
#define FALSE 0;
#define TRUE 1;

int main(int argc, char* argv[]);
int print_instructions(char chrToPlay);
char get_winner(int intW, int intH, char board[intW][intH]);
int print_board2(int intW, int intH, char board[intW][intH]);
int get_and_validate_input(int* x, int* y, int intXUBound, int intYUBound);
int clear_screen();

int main(int argc, char* argv[]){
    //Do something
    //validate inputs
    char winner = ' ';
    char p1 = '+';
    char p2 = '0';
    char player = ' ';
    int intW = 3;
    int intH = 3;
    int intMaxPlays = intW * intH;
    int intPlayCounter = 0;
    //TODO make work for N width
    char chrTicTacBoard[3][3] = {
        {[0 ... 2] = ' '},
        {[0 ... 2] = ' '},
        {[0 ... 2] = ' '}
    };

    int blnInputValid;
    int x;
    int y;
    player = p1;
    //Main loop
    do {
        clear_screen();
        print_board2(intW, intH, &chrTicTacBoard);
        print_instructions(player);
        blnInputValid = get_and_validate_input(&x, &y, intW, intH) + 1;   //Pass pointers for return val
        clear_screen();
        if (blnInputValid){
            if(chrTicTacBoard[x][y] == ' '){
                chrTicTacBoard[x][y] = player;            
                winner = get_winner(intW, intH, &chrTicTacBoard);
                player = (player == p2) ? p1 : p2;
                ++intPlayCounter;
            } else {
                printf("\nThat was an invalid play.\n");
            }
        }
    } while (winner == ' ' && intPlayCounter < intMaxPlays);
    print_board2(intW, intH, &chrTicTacBoard);
    printf("\n\nThe Winner is: ");
    printf("%c\n", winner);
    return EXIT_SUCCESS;
}

int clear_screen(){
    printf("\n\n\n\n\n");
}

int get_and_validate_input(int* x, int* y, int intXUBound, int intYUBound){
    scanf("%d,%d", x, y);
    int intReturnCode = EXIT_FAILURE;
    if ((0 <= x < intXUBound ) && (0 <= y < intYUBound)){
        intReturnCode = EXIT_SUCCESS;
    }
    return intReturnCode;
}

int print_instructions(char chrToPlay){
    printf("Please give coordinates to play your piece in \"x y\" format.\n");
    printf("x and y are indexed from 0. E.G.: $ 0 2 or $ 1 1.\n");
    printf("%c to play: $", chrToPlay);
    return EXIT_SUCCESS;
}

int print_board2(int intW, int intH, char board[intW][intH]){
    char f;
    char delim = '|';
    printf("    ");                 //Space for the row coords
    for (int j = 0; j < intW; ++j){
        printf("%d   ", j);
    }
    printf("\n");
    for (int j = 0; j < intW; ++j){
        printf("%d %c ", j, delim);
        for (int i = 0; i < intH; ++i){
            f = board[i][j];
            printf("%c %c ", board[i][j], delim);
        }
        printf("\n");
    }
    printf("\n");
}

char get_winner(int intW, int intH, char board[intW][intH]){
    char winner = ' ';
    char diagonalTopBottom = board[0][0];
    char diagonalBottomTop = board[intH-1][0];
    char vertical = board[0][0];
    char horizontal = board[0][0];
    for (int i = 0; i < intW && (winner == ' '); ++i){
        vertical = board[i][0];
        horizontal = board[0][i];
        //Check verticals
        for (int j = 0; j < intH; j++){
            if (board[i][j] != vertical){
                vertical = ' ';
            }
        }
        //Check horizontals
        for (int j = 0; j < intH; j++){
            if (board[j][i] != horizontal){
                horizontal = ' ';
            }
        }
        //Check diagonals Top to Bottom (Left to Right)
        if (board[i][i] != diagonalTopBottom){
            diagonalTopBottom = ' ';
        }
        //Check diagonals Bottom to Top (Left to Right)
        if (board[intH-(i+1)][i] != diagonalTopBottom){
            diagonalBottomTop = ' ';
        }

        //End of loop - check for winners on Vertical/Horizontal
        //Vertical / Horizontal:
        if (vertical != ' '){
            winner = vertical;
        }else if (horizontal != ' '){
            winner = horizontal;
        }
    }
    //Check Diagonals only after loop:
    if (diagonalTopBottom != ' '){
        winner = diagonalTopBottom;
    } 
    if (diagonalBottomTop != ' '){
        winner = diagonalBottomTop;
    }
    return winner;
}

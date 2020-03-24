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

size_t arr_length(char *arr);
int print_instructions(char chrToPlay);
int print_board(char **boardTwoStar, char board, char *boardOneStar[]);

int main(int argc, char* argv[]){
    //Do something
    //validate inputs
    //finally
    
    char winner = ' ';
    char p1 = '+';
    char p2 = '0';
    char player = ' ';
    int intW = 3;
    int intH = 3;
    int intMaxPlays = intW * intH;

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
        print_board2(intW, intH, &chrTicTacBoard);
        print_instructions(player);

        blnInputValid = get_and_validate_input(&x, &y);   //Pass pointers for return val
        if (blnInputValid){
            winner = get_winner(intW, intH, &chrTicTacBoard);
            player = (player == p2) ? p1 : p2;
        }
    } while (winner == ' ');

    return EXIT_SUCCESS;
}

int print_instructions(char chrToPlay){
    printf("Please give coordinates to play your piece in x,y format.\n");
    printf("x and y are indexed from 0. E.G.: $ 0,2 or $ 1,1.\n");
    printf("%c to play $ ", chrToPlay);
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

int get_and_validate_input(int* x, int* y){
    int returnVal = EXIT_SUCCESS;

    return EXIT_SUCCESS;
}

//TODO make this work for XxY sized boards
char get_winner(int intW, int intH, char board[intW][intH]){
    char winner = ' ';

    for (int i = 0; i < intW && (winner == ' '); ++i){
        //Check verticals
        if (board[i][0] == board[i][1] == board[i][2]){
            winner = board[i][0];
        }
        //Check horizontals
        if (board[0][i] == board[0][i] == board[0][i]){
            winner = board[i][0];
        }
        //Check diagonals x2
        if (board[0][i] == board[0][i] == board[0][i]){
            winner = board[i][0];
        }
    
    }

    if (board[0][0] == board[1][1] == board [2,2]){
        winner = board[0][0];
    }

    if (board[0][2] == board [1][1] == board [2][0]){
        winner = board[0][0];
    }

    return winner;
}

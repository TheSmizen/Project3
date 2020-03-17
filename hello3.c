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


    do {
        print_board2(intW, intH, &chrTicTacBoard);
        player = (player == p2) ? p1 : p2;
        print_instructions(player);
        winner = get_winner(intW, intH, &chrTicTacBoard)
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
    printf("    ");
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

int get_winner(int intW, int intH, char board[intW][intH]){


    
}

int print_board(char **boardTwoStar, char board, char *boardOneStar[]){

    printf("print_board(chrTicTacBoard, chrTicTacBoard, chrTicTacBoard);\n\n");

    printf("After passing char **boardTwoStar:\n");
    printf("%d sizeof(boardTwoStar)\n", sizeof(boardTwoStar));
    printf("%d sizeof(boardTwoStar)\n",sizeof(boardTwoStar));
    printf("%d sizeof(boardTwoStar[0])\n",sizeof(boardTwoStar[0]));
    printf("%d sizeof(&boardTwoStar)\n",sizeof(&boardTwoStar));
    printf("%d sizeof(&boardTwoStar[0])\n",sizeof(&boardTwoStar[0]));
    
    printf("###\n");
    
    printf("After passing char board:\n");
    printf("%d sizeof(board)\n", sizeof(board));
    printf("%d sizeof(board)\n",sizeof(board));
    //printf("%d sizeof(board[0])\n",sizeof(board[0]));
    printf("%d sizeof(&board)\n",sizeof(&board));
    //printf("%d sizeof(&board[0])\n",sizeof(&board[0]));

    printf("###\n");

    printf("After passing char *boardOneStar:\n");
    printf("%d sizeof(boardOneStar)\n", sizeof(boardOneStar));
    printf("%d sizeof(boardOneStar)\n",sizeof(boardOneStar));
    printf("%d sizeof(boardOneStar[0])\n",sizeof(boardOneStar[0]));
    printf("%d sizeof(&boardOneStar)\n",sizeof(&boardOneStar));
    printf("%d sizeof(&boardOneStar[0])\n",sizeof(&boardOneStar[0]));

    printf("###\n");    
/*
    int intDimY = sizeof(boardTwoStar[0]);
    int intDimX = sizeof(boardTwoStar)/intDimY;

    for (int j = 0; j < intDimX; ++j){
        for (int i = 0; i < intDimY; ++i){
            printf("%c", &boardTwoStar[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/

    return EXIT_SUCCESS;
}
/*
char has_won(char arr[][]){
    char chrReturnVal = ' ';

    //Check verticals
    for (int i = 0; i < 3 && !blnReturnVar; ++i){

        if (arr[i][0] == *arr[i][0] == *arr[i][0]){
            blnReturnVar = TRUE;
            
        }
    }

//    statement ? true : false

    //Check horizontals

    //Check the two diagonals

    return chrReturnVal;
}
*/



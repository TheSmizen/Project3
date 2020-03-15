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

#define OPTSTR "vi:o:f:h"
#define USAGE_FMT "%s [-v] [-f hexflag] [-i inputfile] [-o outputfile] [-h]"
#define ERR_FOPEN_INPUT "fopen(input, r)"
#define ERR_FOPEN_OUTPUT "fopen(output, w)"
#define ERR_DO_THE_NEEDFUL "do_the_needful blew up"
#define DEFAULT_PROGNAME "george"
#define FALSE 0;
#define TRUE 1;

int arr_length(char* arr[]);
int print_instructions(char* chrToPlay);
int print_board(char** board[][]);

int main(int argc, char* argv[]){
    //Do something
    //validate inputs
    //finally
    char chrTicTacBoard[3][3] = {
        {[0 ... 2] = ' '},
        {[0 ... 2] = ' '},
        {[0 ... 2] = ' '}
    };

    printf("test\n");
    print_board(chrTicTacBoard);

    return EXIT_SUCCESS;
}

int arr_length(char* arr[]){
    return EXIT_SUCCESS;
}

int print_instructions(char* chrToPlay){
    printf("Please give coordinates to play your piece in x,y format.\n");
    printf("x and y are indexed from 0. E.G.: $ 0,2 or $ 1,1.\n");
    printf("%c to play $ ",chrToPlay);
    return EXIT_SUCCESS;
}

int print_board(char** board[][]){
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



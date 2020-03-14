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

int do_something(int a);

int main(int argc, char* argv[]){
    //Do something
    //validate inputs
    //finally
    do_something(7);
    return EXIT_SUCCESS;
}

int do_something(int a){
    //do something
    return EXIT_SUCCESS;
}





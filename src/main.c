#include "forth.h"
#include "words.h"
#include "string.h"

#include <stdio.h>

#define MAX_DATA 16384
#define MAX_STACK 16384
#define MAX_RETURN 16384


int main(int argc, char *argv[])
{
    int i;
    FILE * input;
    struct forth forth = {0};
    forth_init(&forth, stdin, MAX_DATA, MAX_STACK, MAX_RETURN);
    words_add(&forth);
    if (argc==1)
    {
        forth.input=stdin;
        forth_run(&forth);
    }
    for (i=1; i<argc;i++)
    {
        if (strncmp(argv[i],"-",1)==0)
        {
            forth.input=stdin;
            forth_run(&forth);
            break;
        }
        input=fopen(argv[i], "r ");
        if (input==NULL)
        {
            printf("Unable to open %s\n", argv[i]);
            continue;
        }
        forth.input=input;
        
        
        forth_run(&forth);
        fclose(input); 
    }
    
    forth_free(&forth);
    return 0;
}

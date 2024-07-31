/*************************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
* Author: Miika Kiljunen
* Date: 6.6.2024
*/
/*************************************************************************/
/*Project 2: Unix Utilities, my-grep.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    FILE *inputStream = stdin;

    char *chars_from_stream = NULL;
    char *pattern = NULL;
    size_t size = 0;
    ssize_t chars_read;

    pattern = argv[1];

    //printf("argc= %i, Arg1= %s, Arg2= %s, pattern= %s\n\n",argc, argv[1],argv[2],pattern); //debug

    //check argument count
    if (argc < 2 || argc > 3){
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 3){
        inputStream = fopen(argv[2], "r");
        if (inputStream == NULL) {
            printf("my-grep: cannot open file\n");
            exit(1);
        }
    }
    
    
    //this part of code uses reference on how to use getline from opensource.com article by Jim Hall. Read 5.6.2024. https://opensource.com/article/22/5/safely-read-user-input-getline
    while ((chars_read = getline(&chars_from_stream, &size, inputStream))!=-1)
    {
        if(strstr(chars_from_stream, pattern) != NULL){
            printf("%s", chars_from_stream);
        }
    } 
    free(chars_from_stream);
    fclose(inputStream);
    

    return 0;
    
}

/* eof */
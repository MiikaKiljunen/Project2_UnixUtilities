/*************************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
* Author: Miika Kiljunen
* Date: 6.6.2024
*/
/*************************************************************************/
/*Project 2: Unix Utilities, my-cat.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    FILE *input_stream;
    char char_from_stream;

    //printf("%s\n\n",argv[1]); //debug

    if(argv[1]!=NULL){

        //for every file, try to open it and print contents
        for (int i=1; i<argc; i++){

            //try to open file
            if ((input_stream = fopen(argv[i], "r")) == NULL) {
                printf("my-cat: cannot open file\n");
                exit(1);
            }
            //print contents
            else{

                //while loop referenced from GeeksForGeeks article. Read 5.6.2024 https://www.geeksforgeeks.org/c-program-print-contents-file/

                char_from_stream = fgetc(input_stream); 
                while (char_from_stream != EOF) 
                { 
                    printf ("%c", char_from_stream); 
                    char_from_stream = fgetc(input_stream); 
                } 
                fclose(input_stream);
            }
        }
    }
    return 0;
    
}

/* eof */
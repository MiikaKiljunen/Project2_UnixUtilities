/*************************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
* Author: Miika Kiljunen
* Date: 6.6.2024
*/
/*************************************************************************/
/*Project 2: Unix Utilities, my-zip.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    int incr = 0;
    char prev_char = '\0';
    int first_file = 1; //for transitioning to multiple files

    for(int i=1; i<argc; i++){

        FILE *unc_input_stream = NULL;

        unc_input_stream = fopen(argv[i], "r");

        if (unc_input_stream == NULL) {
            printf("my-zip: cannot open file\n");
            return 1;
        }

        //while loop basic structure referenced from GeeksForGeeks article. Read 5.6.2024 https://www.geeksforgeeks.org/c-program-print-contents-file/

        char char_from_stream;

        if (first_file) {
            prev_char = fgetc(unc_input_stream);
            if (prev_char == EOF) {
                fclose(unc_input_stream);
                continue;  //skip empty files
            }
            incr = 1;
            first_file = 0;
        }

        while ((char_from_stream = fgetc(unc_input_stream)) != EOF) 
        { 
            //printf ("%c", char_from_stream); //debug

            if(char_from_stream == prev_char){
                incr++;
            }
            else {
                fwrite(&incr, sizeof(int), 1, stdout);
                fwrite(&prev_char, sizeof(char), 1, stdout);
                prev_char = char_from_stream;
                incr = 1;
            }
        } 

        fwrite(&incr, sizeof(int), 1, stdout);
        fwrite(&prev_char, sizeof(char), 1, stdout);
        fclose(unc_input_stream);
    }
    return 0;
}

/* eof */
/*************************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
* Author: Miika Kiljunen
* Date: 6.6.2024
*/
/*************************************************************************/
/*Project 2: Unix Utilities, my-unzip.c*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    for(int i=1; i<argc; i++){

        FILE *c_input_stream = NULL;

        c_input_stream = fopen(argv[i], "rb");

        if (c_input_stream == NULL) {
            printf("my-unzip: cannot open file\n");
            exit(1);
        }
        char char_from_stream;
        int incr;


        //while loop basic structure referenced from GeeksForGeeks article. Read 5. 6.2024 https://www.geeksforgeeks.org/c-program-print-contents-file/

        while (fread(&incr, sizeof(int), 1, c_input_stream) == 1) {
            if (fread(&char_from_stream, sizeof(char), 1, c_input_stream) != 1) {
                fprintf(stderr, "Error reading character from file.\n");
                fclose(c_input_stream);
                return 1;
            }

            for (int i = 0; i < incr; i++) {
                printf("%c",char_from_stream);
            }
        }
        fclose(c_input_stream);
    }

    return 0;
    
}

/* eof */
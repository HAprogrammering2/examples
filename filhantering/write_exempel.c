#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "writetest.txt"
#define BINFILENAME "writetest.bin"

/**
 * @brief Help function, prints heading for examples
 * @param str Heading to print.
 */
void print_example_heading(const char * str){
    printf("\n%s\n", str);
    for (int i = 0; i < strlen(str); i++) {
        putchar('-');
    }
    printf("\n");
}

/**
 * @brief Help function, displays the content of the file on screen.
 * @param filename The file to open and display.
 */
void show_file (const char * filename){
    FILE * fileptr;
    char read_char;
    fileptr = fopen(filename, "r");
    if (fileptr != NULL){
        printf("Filen %s innehåller nu:\n", filename);
        while ((read_char = fgetc(fileptr)) != EOF){
            putchar(read_char);
        }
    }
    printf("\n");
}

/**
 * @brief Help function, does initial work done at the start of each example.
 * @param filename Name of file to open
 * @param heading Description of example about to begin.
 * @return FILE* A pointer to the opened file if successful. Exits otherwise.
 */
FILE * example_init(const char * filename, const char * heading){
    // Open file for writing
    FILE * fileptr = fopen(filename, "w");
    if (fileptr == NULL){
        printf("Could not open file %s, exiting.\n", filename);
        exit(EXIT_FAILURE);
    }

    print_example_heading(heading);
    return fileptr;
}

/**
 * @brief Does cleanup after an example. Closes files. Displays the content of the file.
 * @param fptr Pointer to the file we were using.
 * @param filename The name of the file we were using.
 */
void example_done(FILE * fptr, const char * filename){
    fclose(fptr);
    show_file(filename);
}


int main() {
    FILE *fileptr;
    int day, month, year, a_char, i, count;

    /* ------------------------------------------------------------------------- */
    /* Exempel: fprintf                                                          */
    /* ------------------------------------------------------------------------- */    
    fileptr = example_init(FILENAME, "Skriver datum med fprintf");
    day = 21;
    month = 2;
    year = 2021;

    count = fprintf(fileptr, "%d.%d.%d", day, month, year);

    example_done(fileptr, FILENAME);    
    

    /* ------------------------------------------------------------------------- */
    /* Exempel: fputc                                                            */
    /* ------------------------------------------------------------------------- */    
    fileptr = example_init(FILENAME, "Skriver alfabetet med fputc");

    for (a_char = 'a'; a_char <= 'z'; a_char++){
        fputc(a_char, fileptr);
    }

    example_done(fileptr, FILENAME);


    /* ------------------------------------------------------------------------- */
    /* Exempel: fputs                                                            */
    /* ------------------------------------------------------------------------- */    
    fileptr = example_init(FILENAME, "Skriver en rad med fputs");

    const char * hello = "Hello world";
    fputs(hello, fileptr);

    example_done(fileptr, FILENAME);

    /* ------------------------------------------------------------------------- */
    /* Exempel: fwrite                                                           */
    /* ------------------------------------------------------------------------- */    
    fileptr = example_init(BINFILENAME, "Skriver en räcka med fwrite");
    int sessions [5] = {23, 44, 64, 11, 23};
    fwrite(sessions, sizeof(int), 5, fileptr);

    example_done(fileptr, BINFILENAME);
    printf("\nFilen är binär, så vi får bara rappakalja när vi läser den som text.\n");


    print_example_heading("Läser filen binärt med fread. Lagrar i read_sessions.");
    fileptr = fopen(BINFILENAME, "rb");
    if (fileptr == NULL){
        printf("Could not open file %s, exiting.\n", BINFILENAME);
        return EXIT_FAILURE;
    }

    int read_sessions [5];
    fread(read_sessions, sizeof(int), 5, fileptr);

    for (i=0; i < 5; i++) {
        printf("sessions[%d] = %d, read_sessions[%d] = %d\n", i, sessions[i], i, read_sessions[i]);
    }
}

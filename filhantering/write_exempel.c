#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "writetest.txt"
#define BINFILENAME "writetest.bin"
#define BUFFER_SIZE 80


void print_example_heading(const char * str){
    printf("\n%s\n", str);
    for (int i = 0; i < strlen(str); i++) {
        putchar('-');
    }
    printf("\n");
}

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

int main() {
    FILE *fileptr;
    int day, month, year, a_char, i, chars_read;
    char buffer[BUFFER_SIZE];
    char *line_read;


    // Open file for writing
    fileptr = fopen(FILENAME, "w");
    if (fileptr == NULL){
        printf("Could not open file %s, exiting.\n", FILENAME);
        return EXIT_FAILURE;
    }

    print_example_heading("Skriver alfabetet med fputc");
    for (a_char = 'a'; a_char <= 'z'; a_char++){
        fputc(a_char, fileptr);
    }

    fclose(fileptr);
    show_file(FILENAME);


    // Open file for writing
    fileptr = fopen(FILENAME, "w");
    if (fileptr == NULL){
        printf("Could not open file %s, exiting.\n", FILENAME);
        return EXIT_FAILURE;
    }

    print_example_heading("Skriver en rad med fputs");
    const char * hello = "Hello world";
    fputs(hello, fileptr);


    fclose(fileptr);
    show_file(FILENAME);


    // Open file for writing
    fileptr = fopen(BINFILENAME, "w");
    if (fileptr == NULL){
        printf("Could not open file %s, exiting.\n", BINFILENAME);
        return EXIT_FAILURE;
    }

    print_example_heading("Skriver en räcka med fwrite");
    int sessions [5] = {23, 44, 64, 11, 23};
    fwrite(sessions, sizeof(int), 5, fileptr);

    fclose(fileptr);
    show_file(BINFILENAME);
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
/**
 * @file read_exempel.c
 * @brief Example of reading file in c. Some of these examples depend on the 
 * write_exempel.c file having been compiled and run first. 
 * This file is intended to be compiled and run. You can compare the output 
 * with the file content to learn about how the functions work.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "readtest.txt"
#define BINFILENAME "writetest.bin"
#define BUFFER_SIZE 80

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


int main(){
    FILE * fileptr;
    int day, month, year, a_char, i, chars_read, elements_read;
    char buffer[BUFFER_SIZE];
    char * line_read;

    /* ------------------------------------------------------------------------- */
    /* Setup, making sure we have data to read in the file                       */
    /* ------------------------------------------------------------------------- */
    fileptr = fopen(FILENAME, "w");
    if (fileptr != NULL) {
        fprintf(fileptr, "12.2.2021\n");
        fprintf(fileptr, "Hello world\n");
        fclose(fileptr);
    }

    fileptr = fopen(FILENAME, "r");
    if (fileptr == NULL) {
        printf("Kunde inte öppna filen %s för läsning.", FILENAME);
        exit(EXIT_FAILURE);
    }

    /* ------------------------------------------------------------------------- */
    /* Exempel: fscanf                                                           */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på inläsning med scanf");
    int count = fscanf(fileptr, "%d.%d.%d ", &day, &month, &year);
    printf("Read the following %d values from file: day:%d, month:%d, year:%d\n", count, day, month, year);

    /* ------------------------------------------------------------------------- */
    /* Exempel: fgetc: kompakt version                                           */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på inläsning med fgetc");
    while ((a_char = fgetc(fileptr)) != EOF){
        printf("%c ", a_char);
    }

    // Reached end of file, rewinding to the beginning of the second line so we can read more
    fseek(fileptr, 10, SEEK_SET);


    /* ------------------------------------------------------------------------- */
    /* Exempel: fgetc: längre version                                            */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på inläsning med fgetc, använder returvärdet");
    a_char = fgetc(fileptr);
    while (a_char != EOF){
        printf("%c ", a_char);
        a_char = fgetc(fileptr);
    }

    // Reached end of file, rewinding to the beginning of the file we can read more
    rewind(fileptr);

    /* ------------------------------------------------------------------------- */
    /* Exempel: fgets: kompakt version                                           */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på inläsning med fgets");
    i = 1;
    while (fgets(buffer, 80, fileptr) != NULL){
        printf("Rad %d: %s", i, buffer);
        i++;
    }

    // Reached end of file, rewinding to the beginning of the file we can read more
    rewind(fileptr);

    /* ------------------------------------------------------------------------- */
    /* Exempel: fgets: längre version                                            */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på inläsning med fgetc, använder returvärdet");
    line_read = fgets(buffer, BUFFER_SIZE, fileptr);
    i = 1;
    while (line_read != NULL){
        printf("Rad %d: %s", i, line_read);
        line_read = fgets(buffer, BUFFER_SIZE, fileptr);
        i++;
    }

    // Reached end of file, rewinding rewinding to the beginning of the second line so we can read more
    fseek(fileptr, 10, SEEK_SET);

    /* ------------------------------------------------------------------------- */
    /* Exempel: fread: textfil                                                   */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på inläsning med fread");
    chars_read = fread(buffer, sizeof(char), 80, fileptr);
    if (chars_read != EOF) {
        printf("Läste %d tecken:\n", chars_read);
        printf("%s", buffer);
    }

    fclose(fileptr);

    /* ------------------------------------------------------------------------- */
    /* Exempel: fread: binärfil                                                  */
    /* ------------------------------------------------------------------------- */    
    print_example_heading("Exempel på binär inläsning med fread");
    fileptr = fopen(BINFILENAME, "rb");
    if (fileptr == NULL) {
        printf("Kunde inte öppna filen %s. Kompilera och kör write_exempel.c och försök på nytt.", BINFILENAME);
        exit(EXIT_FAILURE);
    }
    int read_array [5];
    elements_read = fread(read_array, sizeof(int), 5, fileptr);
    printf("Läste %d element från %s: \n", elements_read, BINFILENAME);
    for(i=0; i<elements_read; i++){
        printf("  Element %d: %d\n", i, read_array[i]);
    }

}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "readtest.txt"
#define BINFILENAME "writetest.bin"
#define BUFFER_SIZE 80


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

    // Setup, making sure we have data to read in the file
    fileptr = fopen(FILENAME, "w");
    if (fileptr != NULL) {
        fprintf(fileptr, "12.2.2021\n");
        fprintf(fileptr, "Hello world\n");
        fclose(fileptr);
    }

    fileptr = fopen(FILENAME, "r");
    if (fileptr == NULL) {
        return EXIT_FAILURE;
    }

    // Example of fscanf
    print_example_heading("Exempel på inläsning med scanf");
    int count = fscanf(fileptr, "%d.%d.%d ", &day, &month, &year);
    printf("Read the following values from file: day:%d, month:%d, year: %d\n", day, month, year);

    // Example of fgetc
    print_example_heading("Exempel på inläsning med fgetc");
    while ((a_char = fgetc(fileptr)) != EOF){
        printf("%c ", a_char);
    }

    // Reached end of file, rewinding so we can read more
    fseek(fileptr, 10, SEEK_SET);

    print_example_heading("Exempel på inläsning med fgetc, använder returvärdet");
    a_char = fgetc(fileptr);
    while (a_char != EOF){
        printf("%c ", a_char);
        a_char = fgetc(fileptr);
    }

    // Reached end of file, rewinding so we can read more
    rewind(fileptr);

    // Example of fgets
    print_example_heading("Exempel på inläsning med fgets");
    i = 1;
    while (fgets(buffer, BUFFER_SIZE, fileptr) != NULL){
        printf("Rad %d: %s", i, buffer);
        i++;
    }

    // Reached end of file, rewinding so we can read more
    rewind(fileptr);

    // Same example as before, but catching the return value in char *
    print_example_heading("Exempel på inläsning med fgetc, använder returvärdet");
    line_read = fgets(buffer, BUFFER_SIZE, fileptr);
    i = 1;
    while (line_read != NULL){
        printf("Rad %d: %s", i, line_read);
        line_read = fgets(buffer, BUFFER_SIZE, fileptr);
        i++;
    }


    // Reached end of file, rewinding so we can read more
    fseek(fileptr, 10, SEEK_SET);

    // Example of fread
    print_example_heading("Exempel på inläsning med fread");
    chars_read = fread(buffer, sizeof(char), 80, fileptr);
    if (chars_read != EOF) {
        printf("Läste %d tecken:\n", chars_read);
        printf("%s", buffer);
    }

    fclose(fileptr);

    // Reading binary file
    print_example_heading("Exempel på binär inläsning med fread");
    fileptr = fopen(BINFILENAME, "rb");
    if (fileptr == NULL) {
        return EXIT_FAILURE;
    }
    int read_array [5];
    elements_read = fread(read_array, sizeof(int), 5, fileptr);
    printf("Läste %d element från %s: \n", elements_read, BINFILENAME);
    for(i=0; i<elements_read; i++){
        printf("  Element %d: %d\n", i, read_array[i]);
    }

}
#pragma clang diagnostic pop
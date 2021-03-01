#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Help function to output status of open file.
 * @param fptr The file that was opened
 * @return true if the file was successfully opened, false otherwise
 */
bool verify(FILE * fptr){
    if (fptr == NULL){
        printf("  Could not open file.\n");
        return false;
    }
    else {
        printf("  File successfully opened\n");
        return true;
    }
}

int main(){
    char buffer[80];
    int c;

    // Write some data to file so we have something to test with
    printf("Opening with mode w\n");
    FILE * fptr = fopen("testfil.txt", "w");
    if (verify(fptr)){
        fprintf(fptr, "Hello world\n");
        fprintf(fptr, "Goodbye cruel world");
    }
    fclose(fptr);

    // This should fail, the file already exists
    printf("Opening with mode wx\n");
    fptr = fopen("testfil.txt", "wx");
    if (verify(fptr)){
        fprintf(fptr, "Hello world");
    }
    fclose(fptr);

    // Opening for both reading and writing, experimenting
    printf("Opening with mode r+\n");
    fptr = fopen("testfil.txt", "r+");
    if (verify(fptr)){
        fprintf(fptr, "HELLO");  // Writes in beginning of file
        fscanf(fptr, "%s", buffer);  // What can we read now? Should not be used like this, use fflush and e.g. rewind first
        printf("Read \"%s\" from file\n", buffer);
        fscanf(fptr, "%s", buffer);  // Read one more word, to advance the file pointer
        printf("Read \"%s\" from file\n", buffer);
        fprintf(fptr, " friends"); // Where does this write end up? Should not be used like this, position fptr first.

    }
    fclose(fptr);

    // Showing what the file looks like now after the previous sequence of read/write
    printf("Opening with mode r\n");
    fptr = fopen("testfil.txt", "r");
    do {
        c = fgetc (fptr);
        if (c !=  EOF) {
            printf("%c", c);
        }
    } while (c != EOF);
    printf ("\n");

}

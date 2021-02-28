#include <stdio.h>
#include <stdbool.h>

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

    printf("Opening with mode w\n");
    FILE * fptr = fopen("testfil.txt", "w");
    if (verify(fptr)){
        fprintf(fptr, "Hello world\n");
        fprintf(fptr, "Goodbye cruel world");
    }
    fclose(fptr);

    printf("Opening with mode wx\n");
    fptr = fopen("testfil.txt", "wx");
    if (verify(fptr)){
        fprintf(fptr, "Hello world");
    }
    fclose(fptr);

    printf("Opening with mode r+\n");
    fptr = fopen("testfil.txt", "r+");
    if (verify(fptr)){
        fprintf(fptr, "HELLO");  // Writes in beginning of file
        fscanf(fptr, "%s", buffer);  // Should not be used like this, use fflush and e.g. rewind first
        printf("Read \"%s\" from file\n", buffer);
        fscanf(fptr, "%s", buffer);
        printf("Read \"%s\" from file\n", buffer);
        fprintf(fptr, " friends"); // Should not be used like this, position fptr first.

    }
    fclose(fptr);

    printf("Opening with mode r\n");
    fptr = fopen("testfil.txt", "r");
    do {
        c = fgetc (fptr);
        if (c !=  EOF) {
            printf("%c ", c);
        }
    } while (c != EOF);
    printf ("\n");


}

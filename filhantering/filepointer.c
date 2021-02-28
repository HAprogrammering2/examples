/**
 * @file filepointer.c
 * @brief This example file is intended to be used with a debugger (gdb/lldb) 
 * to look at the _p field of the fptr variable as different read functions 
 * are used.
 */
#include <stdio.h>

int main(){
    char buffer[80];

    // Creating a temporary file to work with.
    FILE * fptr = tmpfile();
    fprintf(fptr, "Hello world.\nGoodbye cruel world.");

    rewind(fptr); // Resetting file pointer to beginning of file.

    fscanf (fptr, "%s", buffer);

    rewind(fptr); // Resetting file pointer to beginning of file.

    fgetc (fptr);

    rewind(fptr); // Resetting file pointer to beginning of file.

    fgets (buffer, 80, fptr);

    rewind(fptr); // Resetting file pointer to beginning of file.
    
    fread (buffer, sizeof(char), 10, fptr);

    // Cleanup
    fclose(fptr);
}

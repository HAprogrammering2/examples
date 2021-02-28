/**
 * @file freopen.c
 * @brief Example that shows how freopen works.
 */
#include <stdio.h>

int main(){

    printf("Välkommen till programmet.\n");
    fprintf(stderr, "Här kommer ett felmeddelande\n");

    freopen("fellogg.txt", "a", stderr);
    fprintf(stderr, "Det här meddelandet kommer inte att synas på skärmen, utan skrivas till fil.\n");

    fclose(stderr);
}

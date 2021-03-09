#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
    char * command_strings [3] = {"add", "delete", "print"};

    // Kolla att vi har fått in rätt antal parametrar
    if (argc == 1){
        printf("Jag vill ha flera parametrar\n");
        return EXIT_FAILURE;
    }

    // Kolla vad användaren skrev för kommando som första parameter
    int selection = 4;  // Ogiltigt kommando representerar jag med 4
    int i = 0;
    while (selection == 4 && i < 3){
        if(strcmp(argv[1], command_strings[i]) == 0){
            // Vi har hittat det kommando som matchar input
            selection = i;
        }
        i++;
    }

    switch(selection) {
        case 0:
            printf("So you want to add stuff?\n");
            break;
        case 1:
            printf("So you want to delete stuff?\n");
            break;
        case 2:
            printf("So you want to print stuff?\n");
            break;
        default:
            printf("Unknown command %s\n", argv[1]);
    }
}

#include <stdio.h>

int main(int argc, char * argv[]){

    printf("Värdet på argc är %d, så jag fick %d parametrar.\n", argc, argc - 1);

    printf("Programmet som anropades var: %s\n", argv[0]);

    for (int i = 1; i<argc; i++){
        printf("argc[%d] = %s\n", i, argv[i]);
    }
}

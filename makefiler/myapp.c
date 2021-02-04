#include "calendar.h"
#include "date.h"
#include "debug.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print_menu(){
    printf("1. Add new entry\n");
    printf("2. Print calendar\n");
    printf("3. Delete entry\n");
    printf("4. Quit\n");
    printf("> ");
}

bool valid_menu_item (int selection){
    switch (selection){
        case 1:
        case 2:
        case 3: 
        case 4:
            return true;
            break;
        default :
            return false;
            break;
    }
}

void clear_buffer(){
    if (!feof(stdin)){
        while (getchar() != '\n') {
        }
    }
}

int read_selection(){
    int selection;

    while (scanf("%d", &selection) != 1 || (!valid_menu_item(selection))){
        printf("Please choose an item from the menu.\n");
        print_menu();
        clear_buffer();
    }
    return selection;
}

int read_number_to_delete(int max){
    int selection;

    while (scanf("%d", &selection) != 1 || (selection>max)){
        printf("Please a number between 1 and %d : ", max);
        clear_buffer();
    }
    return selection;
}

date read_date(){
    date new_date;
    printf ("Please enter a date in format dd.mm.yyyy: ");

    while (scanf("%d.%d.%d", &new_date.day, &new_date.month, &new_date.year) != 3){
        printf("Please enter a date in format dd.mm.yyyy: ");
        clear_buffer();
    }
    clear_buffer();
    return new_date;
}

char * read_message(){
    char buffer[21];
    char * str;
    printf("Please enter a label for the event, no more than 20 characters: ");
    fgets(buffer, 21, stdin);

    buffer[20]= '\0';
    str = (char *)malloc(21*sizeof(char));
    strncpy(str, buffer, 21);

    // Replace newline alternative 1: search and replace
//    char * newlinechr = NULL;
//    newlinechr = strchr(str, '\n');
//    if (newlinechr != NULL){
//        *newlinechr = '\0';
//    }
//    else {
//        clear_buffer();
//    }

    // Replace newline alternative 2: set end of string to NULL
    int last_pos = strnlen(str, 21) - 1;
    if (str[last_pos] == '\n'){
        str[last_pos] = '\0';
    }
    else{
        clear_buffer();
    }

    return str;
}

int main(){
    bool done = false;
    calendar mycal;
    date date;
    char * event = NULL;
    mycal = new_calendar();
    int maxelement = 0;

    while (!done){
        print_menu();
        switch(read_selection()){
            case 1:
                date = read_date();
                event = read_message();     
                printf("Adding %s on date %d.%d.%d\n", event, date.day, date.month, date.year);
                mycal = insert_entry (mycal, date, event);
                break;
            case 2:
                print_calendar(mycal);
                break;
            case 3:
                maxelement = print_calendar_numbered(mycal);
                printf("Which entry should be deleted :");
                mycal = calendar_delete_nth(mycal, read_number_to_delete(maxelement));
                break;
            case 4:
                done = true;
                break;
            default:
                print_menu();
                break;
        }
    }
}

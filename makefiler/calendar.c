#include "calendar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

calendar new_calendar(){
    return NULL;
}

bool calendar_empty(calendar cal) {
    return (cal == NULL);
}

void print_element (date date, char * event){

    print_date(date);
    printf(" %s\n", event);

}

int print_calendar_numbered(calendar calendar)
{
    int index = 1;

    while (calendar != NULL){
        printf("%d. ", index);
        print_element(calendar->date, calendar->event);
        calendar = calendar->next;
        index++;
    }
    return index;
}

void print_calendar(calendar calendar)
{
    while (calendar != NULL){
        print_element(calendar->date, calendar->event);
        calendar = calendar->next;
    }
}

calendar insert_entry (calendar calendar, date date, char * event){
    calendar_entry * current_entry;
    calendar_entry * previous_entry;
    calendar_entry * new_entry;

    new_entry = (calendar_entry *)malloc(sizeof(calendar_entry));
    new_entry->date = date;
    strcpy(new_entry->event, event);

    previous_entry = NULL;
    current_entry = calendar;

    // Find the place to insert the new node
    while (current_entry != NULL && date_is_before(current_entry->date, date)){
        previous_entry = current_entry;
        current_entry = current_entry->next;
    }

    // Current element is now not before new entry, so insert before current element
    new_entry->next = current_entry;

    if (previous_entry != NULL) {
        // Inserting in middle of list.
        previous_entry->next = new_entry;
        return calendar;
    }
    else {
        // Inserting in beginning of list, new_entry the new head.
        return new_entry;
    }
}

calendar calendar_delete_nth(calendar calendar, int n){
        int index = 1;
        calendar_entry * previous = NULL;
        calendar_entry * current = calendar;

        while (current != NULL && index != n){
            previous = current;
            current = current->next;
            index++;
        }

        if (current != NULL){
            if (previous != NULL){
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
            else {
                // Deleting first element
                calendar = calendar->next;
                free(current);
                current = calendar;
            }
        }
        return calendar;
    }

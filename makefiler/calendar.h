#ifndef CALENDARH
#define CALENDARH
#include "date.h"
#define EVENT_NAME_LENGTH 80

struct calendar_entry_struct {
    date date;
    char event[EVENT_NAME_LENGTH];
    struct calendar_entry_struct * next;
};

typedef struct calendar_entry_struct calendar_entry;

typedef calendar_entry * calendar;

/**
 * Function for creating a new, empty calendar.
 * @returns empty calendar
 */
calendar new_calendar();

/**
 * Function for checking if a calendar is empty;
 * @param calendar the calendar to check.
 * @returns true if empty, false otherwise.
 */
bool calendar_empty (calendar calendar);

/**
 * Function for inserting entry into calendar.
 * @param calendar the calendar to insert into. Note, value parameter! Remember to store return value!
 * @param date the date for the new event
 * @param event a string describing the event.
 * @returns the updated calendar.
 */
calendar insert_entry (calendar calendar, date date, char * event);

/**
 * Function for printing the calendar.
 * @param calendar the calendar to print.
 */
void print_calendar(calendar calendar);

/**
 * Function for printing the calendar with numbered items for selection.
 * @param calendar the calendar to print.
 * @returns the number of elements in the list.
 */
int print_calendar_numbered(calendar calendar);

/**
 * Function for deleting a specified element from the list.
 * @param calendar the calendar to delete from.
 * @param n the number of the element to delete.
 * @returns the updated calendar.
 */
calendar calendar_delete_nth(calendar calendar, int n);

#endif

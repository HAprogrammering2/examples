#ifndef DATEH
#define DATEH
#include <stdbool.h>
#include <time.h>

typedef time_t date;

/**
 * Function for creating a new date.
 * @param day the day of the month as an integer
 * @param month the month an integer from 1-12
 * @param year the year as an integer
 * @returns a new date with the values set.
 */
date new_date(int day, int month, int year);

/**
 * Function for comparing two dates.
 * @param first
 * @param second
 * @returns true if the first date is before the second, false otherwise.
 */
bool date_is_before(date first, date second);

/**
 * Function for printing date.
 * @param date date to print
 */
void print_date(date date);

#endif

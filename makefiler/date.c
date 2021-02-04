#include "date.h"
#include <stdio.h>


date new_date(int day, int month, int year){
    date new_date;
    new_date.day = day;
    new_date.month = month;
    new_date.year = year;

    return new_date;
}


bool date_is_before(date first, date second){
    if (first.year < second.year){
        return true;
    }
    if (first.month < second.month){
        return true;
    }
    if (first.day < second.day) {
        return true;
    }
    return false;
}

void print_date(date date){
    printf("%d.%d.%d",date.day, date.month, date.year);
}


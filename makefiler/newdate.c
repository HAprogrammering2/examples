#include "newdate.h"
#include "time.h"
#include <stdio.h>


date new_date(int day, int month, int year){
    date new_date;
    struct tm * timeinfo;
    time_t rawtime;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = 0;
    timeinfo->tm_min = 0;
    timeinfo->tm_sec = 0;

    new_date = mktime(timeinfo);
    return new_date;
}


bool date_is_before(date first, date second){
    return (first < second);

}

void print_date(date date){
    struct tm * timeinfo;
    char outputdate[12];

    timeinfo = localtime(&date);
    strftime(outputdate, 12, "%d.%m.%Y", timeinfo);
    printf("%s", outputdate);
}


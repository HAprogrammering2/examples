#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "date.h"
#include "unittest.h"


int main() {
    calendar mycal;
    date date;


    TEST_CASE("Init")
    mycal = new_calendar();
    VERIFY(calendar_empty(mycal), "New calendar empty")

    TEST_CASE("Insert new event");
    date = new_date(9,2,2021);
    mycal = insert_entry(mycal, date, "Programmering 2");
    VERIFY(!calendar_empty(mycal), "Calendar no longer empty")
    print_calendar(mycal);

    TEST_CASE("Insert multiple events")
    date = new_date(16,2,2021);
    mycal = insert_entry(mycal, date, "Programmering 2");
    date = new_date(18,2,2021);
    mycal = insert_entry(mycal, date, "Programmering 2");
    date = new_date(11,2,2021);
    mycal = insert_entry(mycal, date, "Programmering 2");
    VERIFY(!calendar_empty(mycal), "Calendar no longer empty")
    print_calendar(mycal);

    TEST_CASE("Print numbered")
    print_calendar_numbered(mycal);

    TEST_CASE("Delete third")
    mycal = calendar_delete_nth(mycal, 3);
    print_calendar_numbered(mycal);

}


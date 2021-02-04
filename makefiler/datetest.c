#include <stdio.h>
#include "date.h"
#include "unittest.h"

int main (){
    date date1, date2;
    
    date1 = new_date(25, 10, 2021);
    date2 = new_date(26, 10, 2021);

    TEST_CASE("Comparing 1")
    VERIFY(date_is_before(date1, date2), "Date1 before date2")
    TEST_CASE("Comparing 2")
    VERIFY(!date_is_before(date2, date1), "Date2 not before date1")
    TEST_CASE("Comparing 3")
    VERIFY(!date_is_before(date1, date1), "Date1 not before date1")

}


#include <stdio.h>
#include "date.h"
#include "unittest.h"

int main (){
    date date1, date2;
    
    date1 = new_date(25, 1, 2021);
    date2 = new_date(26, 1, 2021);    

    TEST_CASE("Printing dates")
    print_date(date1);
    printf(" should be 25.1.2021\n");
    print_date(date2);
    printf(" should be 26.1.2021\n");

    TEST_CASE("Comparing 1")
    VERIFY(date_is_before(date1, date2), "Date1 before date2")
    TEST_CASE("Comparing 2")
    VERIFY(!date_is_before(date2, date1), "Date2 not before date1")
    TEST_CASE("Comparing 3")
    VERIFY(!date_is_before(date1, date1), "Date1 not before date1")

}


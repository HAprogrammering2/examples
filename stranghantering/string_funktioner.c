#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void rubrik(const char * msg){
    printf("\n--- %s ---\n", msg);
}

int main (){
    const char * goodbye_string = "Goodbye cruel world.";
    const char * hello_string = "Hello world!\n";

    // ---------------------------------------------------------
    // Längden av en sträng
    rubrik("Längden av en sträng: strlen");
    char hello[] = "Hello world!\n";
    char goodbye[] = "Goodbye cruel world.";

    printf("hello is %lu chars long.\n", strlen(hello));
    printf("goodbye is %lu chars long.\n", strlen(goodbye));

    char * world = hello + 6;
    printf("world is %lu chars long.\n", strlen(world));

    // ---------------------------------------------------------
    // Konkatenering av strängar
    rubrik("Konkatenering av strängar: strcat, strncat");
    char big_hello[44] = "Hello world!\n";
    strcat(big_hello, goodbye);
    printf("Konkatenerad sträng: \'%s\'\n", big_hello);

    strncat(big_hello, goodbye, 10);
    printf("Konkatenerad sträng: \'%s\'\n", big_hello);
    
    // ---------------------------------------------------------
    // Hitta tecken i strängar
    rubrik("Hitta tecken i strängar: strchr, strrchr");
    char * an_l = strchr(hello, 'l');
    printf("Hittade första L:et på \'%s\'\n", an_l);
    
    an_l = strchr(an_l + 1, 'l');
    printf("Hittade andra L:et på \'%s\'\n", an_l);

    an_l = strchr(an_l + 1, 'l');
    printf("Hittade tredje L:et på \'%s\'\n", an_l);

    char * an_o = strrchr(hello, 'o');
    printf("Hittade sista O:et på \'%s\'\n", an_o);

    printf("Sista O:et finns i hello[%ld]\n", an_o - hello);

    // ---------------------------------------------------------
    // Tokenisering av en sträng. 
    rubrik("Strängjämförelse: strcmp, strncmp");

    printf("goodbye och goodbye: %d\n", strcmp("goodbye", "goodbye"));
    printf("good och goodbye: %d\n", strcmp("hell", "goodbye"));
    printf("good och goodbye, 4 bokstäver: %d\n", strncmp("good", "goodbye", 4));
    printf("good5 och good44: %d\n", strcmp("good5", "good44"));

    // ---------------------------------------------------------
    // Kopiering av en sträng.
    rubrik("Kopiering av en sträng: strcpy, strncpy");

    strcpy(goodbye, hello);
    printf("goodbye: %s\n", goodbye);
    
    strcpy (hello, goodbye); // OK, eftersom goodbye innehåller bara "Hello world!\n" efter förra kopieringen
    printf("hello: %s\n", hello);

    // Återställer goodbye
    strcpy(goodbye, goodbye_string);
    // strcpy (hello, goodbye); // Inte OK, goodbye för långt
    strncpy(hello, goodbye, 14);  // OK, men hur går det med nollan?
    printf("hello utan nolla: %s\n", hello);

    //Återställer hello
    strcpy(hello, hello_string);

    strncpy(hello, goodbye, strlen(hello)); // Bättre
    printf("Trygg kopiering till hello: %s\n", hello);

    // ---------------------------------------------------------
    // Tokenisering av en sträng. 
    rubrik("Tokenisering av en sträng, mellanslag och punkt som separator.");

    char * token;
    token = strtok(goodbye, " .");
    while (token != NULL){
        printf("Hittade ord: %s\n", token);
        token = strtok(NULL, " .");
    }
    printf("Och detta innehåller goodbye nu: %s\n", goodbye);

    rubrik("Tokenisering av en sträng, punkt, streck eller snedstreck som separator.");
    char startdate[] = "22.01.2021";
    const char * datesep = "./-";
    char * day   = strtok (startdate, datesep);
    char * month = strtok (NULL, datesep);
    char * year  = strtok (NULL, datesep);

    printf("%d.%02d.%d\n", atoi(day), atoi(month), atoi(year));

    char enddate [] = "25-03-2021";
    day   = strtok (enddate, datesep);
    month = strtok (NULL, datesep);
    year  = strtok (NULL, datesep);

    printf("%d.%02d.%d\n", atoi(day), atoi(month), atoi(year));

    // ---------------------------------------------------------
    // Konvertering från sträng till heltal
    rubrik("Konvertering från sträng till heltal");
    
    printf("%d\n", atoi("12"));
    printf("%d\n", atoi("  12"));
    printf("%d\n", atoi("12blahaj"));
    printf("%d\n", atoi("12 15"));
    printf("%d\n", atoi("blahaj"));

    printf("%ld\n", strtol("12", NULL, 10));
    printf("%ld\n", strtol("  12", NULL, 10));
    printf("%ld\n", strtol("12blahaj", NULL, 10));
    printf("%ld\n", strtol("12 15", NULL, 10));
    printf("%ld\n", strtol("blahaj", NULL, 10));

}

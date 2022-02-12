#include <stdio.h>

int main(){
    int i, day, month, year;
    char str[80];
    FILE * in = stdin; // Använd denna med debuggern för att titta på stdin. Kommandot du kan prova är print in->_p

    // Inläsning av integers, testa t.ex. med:
    // a) en hexadecimal siffra 0xa
    // b) mellanslag innan siffran
    printf("Give me an integer: ");
    scanf ("%i", &i);
    printf ("You wrote \"%d\"\n", i);

    // Inläsning av strängar, testa t.ex. med:
    // a) hello 
    // b) hello world 
    printf ("Give me a string: ");
    scanf ("%s", str);
    printf ("You wrote \"%s\"\n", str);

    // Kompilera om med raden nedan för att se en lösning på problemet
    // fflush (stdin);

    printf ("Give me a string: ");
    scanf ("%s", str);
    printf ("You wrote \"%s\"\n", str);

    fflush(stdin); 

    // Inläsning med blanktecken, testa t.ex. med:
    // a) 14 hello
    // b) 14    hello
    // c) 14hello
    printf ("Give me an integer and a string: ");
    scanf ("%d %s", &i, str);
    printf ("You wrote \"%d\" and \"%s\"\n", i, str);

    fflush(stdin);

    // Inläsning av ett förformatterat datum
    printf ("Give me a date in the format d.m.y: ");
    scanf ("%d.%d.%d", &day, &month, &year);
    printf ("You wrote %d.%d.%d\n", day, month, year);

    fflush(stdin);

    // Inläsning av en sträng med max antal tecken, testa t.ex. med:
    // a) superduper 
    // a) supercalifragilisticexpialidocious
    char buffer [11];
    printf ("Give me a string of max 10 characters: ");
    scanf ("%10s", buffer);
    printf ("You wrote \"%s\"\n", buffer);

    fflush(stdin);

    // Komplicerad inläsning med negerat scanset
    printf ("Give me a number preceded by other characters: ");
    scanf ("%*[^0-9]%d", &i);
    printf ("You wrote \"%d\"\n", i);

}

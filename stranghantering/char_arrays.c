#include <stdio.h>
#include <string.h>

int main(){
    // Vad är en char?
    printf("ASCII-värdet för %c är %d\n", 'a', 'a');

    char * abc = "abc";
    char * skander = "åäö";
    printf("Längden på strängen %s är %lu\n", abc, strlen(abc));
    printf("Längden på strängen %s är %lu\n", skander, strlen(skander));
    
    // Olika sätt att initiera en sträng
    char * hello_const = "Hello world (1)";
    char hello_array1[] = "Hello world (2)";
    char hello_array2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '(', '3', ')', '\0'}; // OBS! Måste nolltermineras explicit

    printf("\n--- Efter initiering ---\n");
    printf("hello_const = %s\n", hello_const);
    printf("hello_array1 = %s\n", hello_array1);
    printf( "hello_array2 = %s\n", hello_array2);

    // Vad händer om vi försöker uppdatera?
    // hello_const[5] = '-';          // Odefinierat vad som händer! Med min kompilator kraschar programmet med felkod: EXEC_BAD_ACCESS
    hello_array1[5] = '-';
    hello_array2[5] = '-';

    printf("\n--- Efter uppdatering ---\n");
    printf("hello_const = %s\n", hello_const);
    printf("hello_array1 = %s\n", hello_array1);
    printf( "hello_array2 = %s\n", hello_array2);

    // Lägg märke till att det är strängen hello_const pekar på som är en konstant. 
    // Variabeln hello_const kan sättas att peka på något annat, som kan ändras.
    hello_const = hello_array1;
    hello_const[5] = '#';

    printf("\n--- Efter uppdatering, hello_const pekar nu på hello_array1 ---\n");
    printf("hello_const = %s\n", hello_const);
    printf("hello_array1 = %s\n", hello_array1);
    printf( "hello_array2 = %s\n", hello_array2);

    printf("\n--- När tar strängen slut? ---\n");
    char goodbye[] = "Goodbye cruel world.\n";
    char hello[] = "Hello world!\n";

    printf ("%s", hello);
    printf ("\n");

    hello[5] = '\n';
    printf ("%s", hello);
    printf ("\n");

    hello[5] = '\0';
    printf ("%s", hello);
    printf ("\n");

    // Vad händer om vi tar bort alla nollor i strängen?
    printf("\n--- Och om vi tar bort alla nollor i strängen? ---\n");
    hello[5] = ' ';
    hello[13] = ' ';
    printf ("%s", hello);
    printf ("\n");    
}

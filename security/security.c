#include <stdio.h>

void vulnerable_print(char * malicious_input) {
	printf(malicious_input);
}

int main () {
    char buffer[10];
    char * message = "Bra jobbat!";

    printf("Vad vill du skriva ut > ");
    gets(buffer); // Vad händer om användaren skriver mer än 10 tecken?

    vulnerable_print(buffer);  // Vad händer om användaren matade in en formatsträng?

    printf("\n%s\n", message);
}

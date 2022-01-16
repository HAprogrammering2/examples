#include <stdio.h>
#include <stdbool.h>

int main (){
    // ------------------------------------------------
    // Enkla datatyper
    int day = 3;
    char selection = 'q';

    printf("The addresses of day and selection:\n");
    printf ("&day: %p\n", &day);
    printf ("&selection: %p\n", &selection);

    // Pekare
    int * dayptr = &day;
    char * sptr = &selection;
    printf("\nThe values of the pointer variables:\n");
    printf ("dayptr: %p\n", dayptr);
    printf ("sptr: %p\n", sptr);

    printf ("\nWhat the pointers point to:\n");
    printf ("*dayptr: %d\n", *dayptr);
    printf ("*sptr: %c\n", *sptr);

    // ------------------------------------------------
    // Pekare till pekare
    int ** ptrptr = &dayptr;

    printf("\nThe value of the pointer variable:\n");
    printf ("ptrptr: %p\n", ptrptr);

    printf ("\nWhat the pointer points to:\n");
    printf ("*ptrptr: %p\n", *ptrptr);

    printf ("\nWhat the pointer pointed to the by the pointer points to:\n");
    printf ("**ptrptr: %d\n", **ptrptr);

    // ------------------------------------------------
    // Sammansatta datatyper 
    int sessions[5] = {12, 7, 3, 8, 42};
    char name[20] = "Jeanette";
    struct person {
            int age;
            char name[20];
            bool programmer;
    };

    struct person jeanette = {25, "Jeanette", true};

    printf("\nThe values of the fields of the struct are:\n");
    printf("jeanette.age: %d\n", jeanette.age);
    printf("jeanette.name: %s\n", jeanette.name);
    printf("jeanette.programmer: %d\n", jeanette.programmer);

    struct person * jptr = &jeanette;

    printf("\nThe values of the fields of the struct are:\n");
    printf("jptr->age: %d\n", jptr->age);
    printf("jptr->name: %s\n", jptr->name);
    printf("jptr->programmer: %d\n", jptr->programmer);

    printf("\nCompare with access using (*jptr).field:\n");
    printf("(*jptr).age: %d\n", (*jptr).age);
    printf("(*jptr).name: %s\n", (*jptr).name);
    printf("(*jptr).programmer: %d\n", (*jptr).programmer);

    // ------------------------------------------------
    // Räckor är speciella, de är redan pekare
    int * arrptr1 = sessions;

    printf("\nCompare accessing fourth element of the array and the pointer.\n");
    printf ("sessions[3]: %d\n", sessions[3]);
    printf ("arrptr1[3]: %d\n", arrptr1[3]);

    int * arrptr2 = &sessions[0];
    printf("\nCompare accessing fourth element of the array and the pointer.\n");
    printf ("sessions[3]: %d\n", sessions[3]);
    printf ("arrptr2[3]: %d\n", arrptr2[3]);

}

#include <stdio.h>

int main(){
    int single;

    while(scanf("%d", &single) == 1){
        printf("%d\n", single * 2);
        fprintf(stderr, "Läste %d, beräknade %d\n", single, single*2);
    }
}

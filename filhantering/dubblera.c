#include <stdio.h>

int main(){
    int single;

    // freopen("errlogg.txt","a", stderr);

    while(scanf("%d", &single) == 1){
        printf("%d\n", single * 2);
        fprintf(stderr, "Läste %d, beräknade %d\n", single, single*2);
    }
}

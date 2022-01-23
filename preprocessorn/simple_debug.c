#include <stdio.h>

#ifdef DEBUG_ON
#define DEBUG(msg) printf("DEBUG: %s\n", msg);
#else
#define DEBUG(msg)
#endif

int main(int argc, char * argv[]){
    DEBUG("Program started");
    printf("Hello world!\n");
}

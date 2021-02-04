#include <stdio.h>

#ifdef DEBUG_ON
#define DEBUG(fmt, ...) printf("DEBUG: file: %s line: %d: ", __FILE__, __LINE__); printf(fmt, __VA_ARGS__); printf("\n");
#else
#define DEBUG(fmt, ...)
#endif

int main(int argc, char * argv[]){
    int day = 3;
    int sessions[5] = {12,7,3,8,42}; 
    int * dayptr = &day;
    int ** ptrptr = &dayptr;
    char name[20] = "Jeanette";
    printf("Hello world %s\n", name);
    DEBUG("Pointer to pointer points to %d", **ptrptr)
}

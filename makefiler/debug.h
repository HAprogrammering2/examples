#ifndef DEBUGH
#define DEBUGH

#define DEBUGON
#ifdef DEBUGON
#define DEBUG(msg) fprintf(stderr, "DEBUG: %s\n", msg)
#define DEBUG_ADDR(msg, ptr) fprintf(stderr, "DEBUG: %s %p\n", msg, (void *)ptr)
#else
#define DEBUG(msg)
#define DEBUG_ADDR(msg, ptr)
#endif // DEBUGON

#endif // DEBUGH


#ifndef UNITTESTH
#define UNITTESTH
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name);
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);
#endif

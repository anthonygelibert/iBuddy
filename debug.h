#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>
#include <unistd.h>

#if DEBUG
/** Display the debug logs. */
#define PRINTF(...) fprintf(stderr,__VA_ARGS__);
#else
/** Don't display the debug logs. */
#define PRINTF(...)
#endif

#endif /* DEBUG_H_ */

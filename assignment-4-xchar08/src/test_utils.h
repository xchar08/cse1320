#ifndef TEST_UTILS_H_
#define TEST_UTILS_H_

#include <stdint.h>

#define SEC_TO_MS(x) ((x) * 1000)
#define NS_TO_MS(x)  ((x) / 1000000)

uint64_t benchmark_function(void (*)(int, int), int, int);


#endif

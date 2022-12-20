#include "test_utils.h"
#include <stdint.h>
#include <time.h>


uint64_t benchmark_function(void (*f)(int, int), int num_samples, int sample_size) {
    struct timespec ts;

    // Checkpoint 1
    int return_code = timespec_get(&ts, TIME_UTC);
    uint64_t ms1 = SEC_TO_MS((uint64_t)ts.tv_sec) + NS_TO_MS((uint64_t)ts.tv_nsec);

    // Call function to benchmark
    f(num_samples, sample_size);

    // Checkpoint 2
    return_code = timespec_get(&ts, TIME_UTC);
    uint64_t ms2 = SEC_TO_MS((uint64_t)ts.tv_sec) + NS_TO_MS((uint64_t)ts.tv_nsec);

    return ms2 - ms1;
}

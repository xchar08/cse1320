#include <stdio.h>
#include <stdlib.h>

#include "array_tests.h"
#include "linked_list_tests.h"
#include "test_utils.h"

void run_array_tests(int num_samples, size_t sample_size) {
    // Run benchmark 1
    printf("* Sequential Insert Test - Single Resize Strategy\n");
    printf("  %ld ms\n", benchmark_function(array_push1, num_samples, sample_size));
    
    // Run benchmark 2
    printf("* Sequential Insert Test - 2x Resize Strategy\n");
    printf("  %ld ms\n", benchmark_function(array_push2, num_samples, sample_size));

    printf("* Random Insert Test - Single Resize Strategy\n");
    printf("  %ld ms\n", benchmark_function(array_random_insert_single, num_samples, sample_size));

    printf("* Random Insert Test - 2x Resize Strategy\n");
    printf("  %ld ms\n", benchmark_function(array_random_insert_double, num_samples, sample_size));
}

void run_linked_list(int num_samples, size_t sample_size) {
    printf("* Sequential Insert Test - Start Of List\n");
    printf("  %ld ms\n", benchmark_function(linked_list_insert_sequential_start, num_samples, sample_size));

    printf("* Sequential Insert Test - End Of List\n");
    printf("  %ld ms\n", benchmark_function(linked_list_insert_sequential_end, num_samples, sample_size));

    printf("* Sequential Insert Test - Random Position\n");
    printf("  %ld ms\n", benchmark_function(linked_list_insert_random, num_samples, sample_size));
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("USAGE: ./array_test NUM_SAMPLES SAMPLE_SIZE\n");
        return 1;
    }

    int num_samples = atoi(argv[1]);
    size_t sample_size = atoi(argv[2]);

    run_array_tests(num_samples, sample_size);
    run_linked_list(num_samples, sample_size);
    return 0;
}

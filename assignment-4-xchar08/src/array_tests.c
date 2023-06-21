#include <stdlib.h>

#include "array_utils.h"

void array_push1(int num_samples, int sample_size) {
    array_s arr = { 0 };

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        push(sample, &arr);
    }

    for (int i = 0; i < arr.numel; i++) {
        free(arr.data[i]);
    }
}

void array_push2(int num_samples, int sample_size) {
    array_s arr = { 0 };

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        push_c(sample, &arr);
    }

    for (int i = 0; i < arr.numel; i++) {
        free(arr.data[i]);
    }
}

/*
 * Inserts a new element in a random location between [0, numel].
 * Uses a single reallocation strategy.
 */
void array_random_insert_single(int num_samples, int sample_size) {
    array_s arr = { 0 };

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        int idx = rand() % (arr.numel + 1);
        add(sample, &arr, idx);
    }

    for (int i = 0; i < arr.numel; i++) {
        free(arr.data[i]);
    }
}

/*
 * Inserts a new element in a random location between [0, numel].
 * Uses a 2x reallocation strategy.
 */
void array_random_insert_double(int num_samples, int sample_size) {
    array_s arr = { 0 };

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        int idx = rand() % (arr.numel + 1);
        add_c(sample, &arr, idx);
    }

    for (int i = 0; i < arr.numel; i++) {
        free(arr.data[i]);
    }
}

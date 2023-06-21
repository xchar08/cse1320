#include <stdio.h>
#include <stdlib.h>

#include "array_utils.h"

int add(void *data, array_s *arr, int pos) {
    if (pos < 0 || pos > arr->numel || data == NULL || arr == NULL) {
        return 1;
    }

    // Resize our array
    arr->data = realloc(arr->data, (arr->numel + 1) * sizeof(void *));

    // Shift contents
    for (int i = arr->numel; i > pos; i--) {
        arr->data[i] = arr->data[i-1];
    }

    // Insert the element
    arr->data[pos] = data;
    arr->numel++;

    return 0;
}

/*
 * add_c - Add item to an array.
 *
 * Uses the `capacity` variable to resize only when the capacity is reached.
 */
int add_c(void *data, array_s *arr, int pos) {
    if (pos < 0 || pos > arr->numel || data == NULL || arr == NULL) {
        return 1;
    }

    // Check init size
    if (arr->capacity == 0) {
        arr->data = calloc(INIT_SIZE, sizeof(void *));
        arr->capacity = INIT_SIZE;
    }

    // Resize our array
    if (arr->numel + 1 == arr->capacity) {
        arr->data = realloc(arr->data, arr->capacity * CAP_FACTOR * sizeof(void *));
        arr->capacity *= CAP_FACTOR;
    }

    // Shift contents
    for (int i = arr->numel; i > pos; i--) {
        arr->data[i] = arr->data[i-1];
    }

    // Insert the element
    arr->data[pos] = data;
    arr->numel++;

    return 0;
}

int push(void *elem, array_s *arr) {
    return add(elem, arr, arr->numel);
}

int push_c(void *elem, array_s *arr) {
    return add_c(elem, arr, arr->numel);
}

void *pop_p(array_s *arr, int pos) {
    // Error checking
    if (arr == NULL || pos < 0 || pos >= arr->numel) {
        return NULL;
    }

    // Get the data requested
    void *elem = arr->data[pos];

    // Shift data
    for (int i = pos; i < arr->numel - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }

    // Realloc
    arr->data = realloc(arr->data, (arr->numel - 1) * sizeof(void *));
    arr->numel--;

    return elem;
}

void *pop(array_s *arr) {
    return pop_p(arr, arr->numel-1);
}
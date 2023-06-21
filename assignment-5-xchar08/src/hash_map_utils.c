#include "hash_map_utils.h"
#include "array_utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Prints a single `hash_element_t`.
 *
 * Args:
 *  hash_element_t *elem - The key-value element to print.
 *  void print_fn(void *) - A pointer to a function which prints the data stored in `elem->value`.
 */
void print_element(hash_element_t *elem, void (*print_fn)(void *)) {
    if (elem) {
        printf("(%s, ", elem->key);
        print_fn(elem->value);
        printf(")\n");
    } else {
        printf("EMPTY\n");
    }
}

/*
 * Prints all entries in the map.
 *
 * Args:
 *  hash_map_t *map - A pointer to the map object.
 *  void print_fn(void *) - A pointer to a function which prints the data stored in each element.
 */
void print_map(hash_map_t *map, void (*print_fn)(void *)) {
    if (map->temp) {
        for (int i = 0; i < map->temp_size; i++) {
            printf("temp_map[%d] = ", i);
            print_element(map->temp[i], print_fn);
        }
    }
    if (map->primary) {
        for (int i = 0; i < map->map_size; i++) {
            printf("new_map[%d] = ", i);
            print_element(map->primary[i], print_fn);
        }
    }
}

/*
 * The value of an element is `void *` so that it may take on
 * any data type that the user wants.
 *
 * Args:
 *  hash_element_t *elem - The key-value element to be freed.
 *  void free_fn(void *) - A pointer to a function which can free the elements value.
 */
void free_element(hash_element_t *elem, void (*free_fn)(void *)) {
    if (elem) {
        free(elem->key);
        free_fn(elem->value);
        free(elem);
    }
}

/*
 * Releases all memory allocated for the current map,
 * including the pointer for the hash_map_t struct itself.
 */
void free_map(hash_map_t *map, void (*free_fn)(void *)) {
    if (map) {
        if (map->temp) {
            for (int i = 0; i < map->temp_size; i++) {
                free_element(map->temp[i], free_fn);
            }

            free(map->temp);
        }

        if (map->primary) {
            for (int i = 0; i < map->map_size; i++) {
                free_element(map->primary[i], free_fn);
            }

            free(map->primary);
        }

        free(map);
    }
}

int hash_function(char *key) {
    int hash = 0;

    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }

    return hash;
}

int compute_index(char *key, int map_size) {
    int hash = hash_function(key);
    int index = hash % map_size;

    return index;
}

int quadratic_probe(int hash, int i, int c1, int c2){
    return hash+c2*i*i+c1*i;
}

double compute_load_factor(int num_keys, int bucket_size) {
    return (double)num_keys / bucket_size;
}

/*
 * Initializes the map to a given `size`.
 */
void init_map(hash_map_t *map, int size) {
    map->primary = calloc(size, sizeof(void *));
    map->map_size = size;
}

/*
 * Searches a map that implements incremental rehashing.
 * It is necessary to check both the old and new maps
 * when searching for a key.
 *
 * Returns NULL if no such key was found.
 */
hash_element_t *search(hash_map_t *map, char *key) {
    if (map->temp != NULL) {
        int index = compute_index(key, map->temp_size);
        hash_element_t *elem = map->temp[index];
        if (!elem) {
            return NULL;
        }
        if (!strcmp(map->temp[index]->key, key)) {
            return map->temp[index];
        }
    } else if (map->primary != NULL) {
        int index = compute_index(key, map->map_size);
        hash_element_t *elem = map->primary[index];
        if (!elem) {
            return NULL;
        }
        if (!strcmp(map->primary[index]->key, key)) {
            return map->primary[index];
        }
    }

    return NULL;
}

/*
 * Performs an all-at-once rehash.
 */
void rehash_aio(hash_map_t *hash_map) {
    // TODO (Class): Implement AIO rehashing.
}

/*
 * Performs incremental rehashing on the map.
 */
void rehash_inc(hash_map_t *map) {
    for (int i = 0; i < R_VALUE; i++) {
        // If there is nothing to rehash at the moment, return immediately.
        if (map->temp == NULL) {
            return;
        }

        // Iterate to next non-null value
        while (map->temp[map->temp_index] == NULL && map->temp_index < map->temp_size) {
            map->temp_index++;
        }

        // Check if temp map is empty
        if (map->temp_index == map->temp_size) {
            free(map->temp);
            map->temp = NULL;
            map->temp_index = 0;

            return;
        }

        hash_element_t *elem = map->temp[map->temp_index];
        int index = compute_index(elem->key, map->map_size);
        int i = 0;
        while (map->primary[index] != NULL) {
            // TODO: Call your quadratic probing function to update `index`.
            // index = ...
            //index = default_probe((int)(elem->value),i);
            i++;
        }

        map->primary[index] = elem;

        printf("Rehashing %s into %d\n", elem->key, index);

        map->temp[map->temp_index] = NULL;
    }
}

/*
 * Assumes that the element does not currently exist.
 */
void insert(hash_map_t *map, hash_element_t *elem) {
    double factor = compute_load_factor(map->num_keys + 1, map->map_size);

    // printf("[DEBUG] factor = %.2lf\n", factor);

    if (factor >= LOAD_FACTOR) {
        printf("Beginning rehash...\n");
        // Begin rehash
        map->temp = map->primary;
        map->temp_size = map->map_size;
        // TODO: Compute factor dynamically
        map->primary = calloc(map->map_size * 2, sizeof(void *));
        map->map_size *= 2;
    }

    int index = compute_index(elem->key, map->map_size);

    while (map->primary[index] != NULL) {
        // TODO: Call your quadratic probing function to update `index`.
        // index = ...
        //index = default_probe(map->primary[index],index);
    }

    printf("Inserting %s at %d\n", elem->key, index);

    map->primary[index] = elem;
    map->num_keys++;

    rehash_inc(map);
}

/*
 * Assumes that the element does not currently exist.
 * HINT: Use this function when inserting bulk data since it will not trigger a rehash.
 */
void insert_no_rehash(hash_map_t *map, hash_element_t *elem) {
    int index = compute_index(elem->key, map->map_size);

    if (map->primary[index]) {
        // TODO: Call your quadratic probing function to update `index`.
        // index = ...
        //index = default_probe(map->primary[index],index);
    }

    printf("Inserting %s at %d\n", elem->key, index);

    map->primary[index] = elem;
    map->num_keys++;
}

/*void reserve(hash_map_t map, int new_size) {
    // Resize and Rehash
    hash_element_t **temp_map = calloc(new_size, sizeof(void));

    for(int i = 0; i < map.map_size; i++) {
        hash_element_t *elem = map.primary[i];

        if(elem == NULL) {
            continue;
        }

        int index = compute_index(elem->key, new_size);
        int hash = hash_function(elem->key);
        int i = 1;

        while(temp_map[index] != NULL) {
            // Call your quadratic probing function to update index
            index = default_probe(hash, i) % map.map_size;
        }

        printf("Inserting %s at %d\n", elem->key, index);

        temp_map[index] = elem;
    }

    map.primary = temp_map;
    map.map_size = new_size;
    free(map.primary);
} */

/*
 * Inserts a collection of elements into the map.
 * If the map is currently undergoing a rehash, hash the remaining
 * entries from the temporary map into the primary map.
 *
 * Args:
 *  hash_map_t map - The hash map.
 *  array_s elements - An array of `hash_element_t` objects.
 */
/*void bulk_insert(hash_map_t *map, array_s elements) {
    // if the map is currently rehashing, dump the rest of the elements before reserving
    int num_keys = elements.numel;
    double new_size = bucket_size(elements.numel, LOAD_FACTOR);
    // Reserve enough space to accommodate adding all elements in the array.
    while(map->temp!=NULL){
        rehash_inc(map);
    }
    
    reserve(*map, new_size);
    for(int i = 0; i<map->map_size; i++){
        insert_no_rehash(map,elements.data[i]);
    }
    // The macro created earlier will compute this number.
    // Insert all elements into the map using `insert_no_rehash`.
}*/




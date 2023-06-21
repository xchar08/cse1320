#ifndef HASH_MAP_UTILS_H_
#define HASH_MAP_UTILS_H_

#define LOAD_FACTOR 0.7
#define R_VALUE 1

typedef struct {
    char *key;
    void *value;
} hash_element_t;

typedef struct {
    hash_element_t **temp;
    hash_element_t **primary;
    int num_keys;
    int temp_size;
    int map_size;
    int temp_index;
} hash_map_t;

int hash_function(char *);
int compute_index(char *, int);
int quadratic_probe(int hash, int i, int c1, int c2);
void init_map(hash_map_t *, int);
hash_element_t *search(hash_map_t *, char *);
void rehash_aio(hash_map_t *);
void rehash_inc(hash_map_t *);
void insert(hash_map_t *, hash_element_t *);
void print_element(hash_element_t *, void (*)(void *));
void print_map(hash_map_t *, void (*)(void *));
void free_element(hash_element_t *, void (*)(void *));
void free_map(hash_map_t *, void (*)(void *));
void insert_no_rehash(hash_map_t *, hash_element_t *);

#define default_probe(hash,i) quadratic_probe(hash,i,1,1)
#define bucket_size(n, b) (int)(ceil((double)n / b));

#endif
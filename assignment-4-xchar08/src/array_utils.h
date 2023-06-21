#define CAP_FACTOR 2
#define INIT_SIZE 8

typedef struct {
    void **data;
    int numel;
    int capacity;
} array_s;

int add(void *, array_s *, int);
int add_c(void *, array_s *, int);
int push(void *, array_s *);
int push_c(void *, array_s *);
void *pop_p(array_s *, int);
void *pop(array_s *);
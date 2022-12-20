#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 128

void trim(char *str);

typedef struct {
    char **data;
    int num_items;
} mystack_t;

void push(char *val, mystack_t *stack);
char *pop(mystack_t *stack);
void print_stack(mystack_t *stack);
char *read_string();
void print_tabs(int num_tabs);
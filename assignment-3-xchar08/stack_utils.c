#include "stack_utils.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void push(char *val, mystack_t *stack) {
    stack->data = realloc(stack->data, (stack->num_items + 1) * sizeof(void *));
    stack->data[stack->num_items++] = val;
}

char *pop(mystack_t *stack) {
    char *str = stack->data[stack->num_items - 1];
    stack->data = realloc(stack->data, --stack->num_items * sizeof(void *));

    return str;
}

void print_stack(mystack_t *stack) {
    for (int i = stack->num_items - 1; i >= 0; i--) {
        printf("%s\n", stack->data[i]);
    }
    printf("\n");
}

char *read_string() {
    char buffer[BUF_SIZE] = { 0 };
    printf("Enter a string: ");
    fgets(buffer, BUF_SIZE, stdin);
    buffer[strlen(buffer) - 1] = 0;
    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);
    return str;
}

void print_tabs(int num_tabs){ 
    char tabs[BUF_SIZE] = "  ";  
    for(int i = 0; i < num_tabs-1; i++){
        strcat(tabs,"   ");
    }
    trim(tabs);
    fprintf(stdout,"%s",tabs);
}
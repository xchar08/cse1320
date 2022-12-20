#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int roll;
    int position;
} player_s;

typedef struct {
    void **data;
    int numel;
} array_s;

void trim(char *str);
player_s *create_player(char* name, int position);
void rolld20(array_s *arr);
char *get_string();
int enqueue(void *, array_s *);
void *dequeue(array_s *);
void print_queue(array_s *arr);
void show_menu();
void peek(array_s *);
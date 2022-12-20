#include "queue_utils.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

player_s *create_player(char* name, int position) {
  player_s *player = malloc(sizeof(player_s));
  player -> name = name;
  player -> roll = rand() % 20 + 1;
  player -> position = position;
  return player;
}

void rolld20(array_s *arr) {
    for (int i = 0; i < arr->numel; i++) {
        int randint = rand() % 20 + 1;
        ((player_s *)(arr->data[i]))->roll = randint;
        fprintf(stdout,"%s rolled a %d.\n", (((player_s *)(arr->data[i]))->name), randint);
    }
}

char *get_string() {
    char buffer[128] = { 0 };
    fprintf(stdout,"> ");
    fgets(buffer, 128, stdin);
    trim(buffer);
    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}

int enqueue(void *elem, array_s *arr) {
    // error checking
    if (elem == NULL || arr == NULL) {

        return 1;
    }

    // resize array
    arr->data = realloc(arr->data, (arr->numel + 1) * sizeof(void *));

    // put the element in the array
    // increment numel
    arr->data[arr->numel++] = elem;

    // return an error code
    return 0;
}

void *dequeue(array_s *arr) {
    // error checking
    if (arr == NULL || arr->data == NULL) {
        return NULL;
    }

    // retrieve the desired element
    void *elem = arr->data[0];

    // shift the data
    for (int i = 0; i < arr->numel - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }

    // resize the array
    arr->data = realloc(arr->data, (arr->numel - 1) * sizeof(void *));

    // decrement numel
    arr->numel--;

    // return element
    return elem;
}

void peek(array_s *arr){
    if (arr != NULL || arr->data != NULL) {
        fprintf(stdout, "%s\'s Turn!\n", ((player_s *)(arr->data[0]))->name);
    }
}

void print_queue(array_s *arr) {
    for (int i = 0; i < arr->numel; i++) {
        fprintf(stdout,"%d. %s\n", ((player_s *)(arr->data[i]))->position, ((player_s *)(arr->data[i]))->name);
    }
}

void show_menu() {
    fprintf(stdout,"\n1. Add Player\n");
    fprintf(stdout,"2. Roll Initiative\n");
    fprintf(stdout,"3. Next Turn\n");
    fprintf(stdout,"4. View Current Order\n");
}
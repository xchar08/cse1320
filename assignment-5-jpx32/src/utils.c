#include "utils.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

char *get_string() {
    char buffer[128] = { 0 };
    //printf("Enter a string: ");
    fgets(buffer, 128, stdin);
    trim(buffer);

    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}

#ifndef MONSTER_UTILS_H_
#define MONSTER_UTILS_H_

#define MAX_LEN 128

#include "array_utils.h"
#include <stdio.h>

typedef struct {
    char *name;
    char *type;
    int hp;
    int ac;
    int str;
    int dex;
    int con;
} monster_s;

void free_monster(void *);
monster_s *create_monster();
monster_s *parse_monster(char *);
void print_monster(void *);
array_s load_monsters_csv(FILE *);

#endif

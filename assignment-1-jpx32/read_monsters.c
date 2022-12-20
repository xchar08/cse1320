#include <stdio.h>

#include "monster_utils.h"

int main(void) {
    char names[MAX_MONSTERS][MAX_STR] = { 0 };
    char types[MAX_MONSTERS][MAX_STR] = { 0 };
    int hp[MAX_MONSTERS] = { 0 };
    int ac[MAX_MONSTERS] = { 0 };
    int str[MAX_MONSTERS] = { 0 };
    int dex[MAX_MONSTERS] = { 0 };
    int con[MAX_MONSTERS] = { 0 };
    int num_monsters = 0;

    num_monsters = read_monster(names, types, hp, ac, str, dex, con, num_monsters);

    printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n", names[0], types[0], hp[0], ac[0], str[0], dex[0], con[0]);

    return 0;
}
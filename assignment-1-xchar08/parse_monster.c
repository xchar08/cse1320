#include "monster_utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char names[][MAX_STR] = {0};
    char types[][MAX_STR] = {0};
    int hp[] = {1};
    int ac[] = {1};
    int str[] = {1};
    int dex[] = {1};
    int con[] = {1};
    read_monster(names, types, 
    hp,
    ac,
    str,
    dex,
    con,
    0);
    char stru[4095];
    printf("Enter a line of CSV: ");
    scanf   ("%s", &stru);
    parse_monster(stru, names, types, 
    hp,
    ac,
    str,
    dex,
    con,
    1);
    write_monsters(names, types, 
    hp,
    ac,
    str,
    dex,
    con,
    2, "monsters.csv");
    search_monsters(names,
    types,
    hp,
    ac,
    str,
    dex,
    con,
    3,
    "Jerry");
}
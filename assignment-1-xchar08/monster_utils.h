#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_MONSTERS 32
#define MAX_STR 64

void trim(char str[]);
int read_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters);

int write_monsters(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char filename[]);

int parse_monster(char line[], 
    char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters);
    
int search_monsters(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char term[]);
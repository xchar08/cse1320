#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "monster_utils.h"

void trim(char str[]) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

int read_monster(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters) {

    if (num_monsters == MAX_MONSTERS) {
        return num_monsters;
    }

    printf("Enter a name: ");
    fgets(names[num_monsters], MAX_STR, stdin);
    trim(names[num_monsters]);

    printf("Enter a type: ");
    fgets(types[num_monsters], MAX_STR, stdin);
    trim(types[num_monsters]);

    printf("Enter HP: ");
    scanf("%d", &hp[num_monsters]);

    printf("Enter AC: ");
    scanf("%d", &ac[num_monsters]);

    printf("Enter STR: ");
    scanf("%d", &str[num_monsters]);

    printf("Enter DEX: ");
    scanf("%d", &dex[num_monsters]);

    printf("Enter CON: ");
    scanf("%d", &con[num_monsters]);

    return num_monsters + 1;
}

int write_monsters(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char filename[]){
    FILE* file;
    file = fopen(filename,"w");
    for(int i = 0; i < num_monsters; i++){
        fprintf(file, "%s,%s,%d,%d,%d,%d,%d\n", names[i], types[i], hp[i], ac[i], str[i], dex[i], con[i]);
    }
}

int parse_monster(char line[], 
    char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters){
        int attr = 0;
        int addr = num_monsters;
        char *token = strtok(line, ",");
        strcpy(names[addr], token);
        attr++;
        token = strtok(NULL, ",");
        strcpy(types[addr], token);
        attr++;
        token = strtok(NULL, ",");
        hp[addr] = atoi(token);
        attr++;
        token = strtok(NULL, ",");
        ac[addr] = atoi(token);
        attr++;
        token = strtok(NULL, ",");
        str[addr] = atoi(token);
        attr++;
        token = strtok(NULL, ",");
        dex[addr] = atoi(token);
        attr++;
        token = strtok(NULL, ",");
        con[addr] = atoi(token);
        attr++;
        printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON",names[addr],types[addr],hp[addr],ac[addr],str[addr],dex[addr],con[addr]);
        return attr;
}

int search_monsters(char names[][MAX_STR],
    char types[][MAX_STR],
    int hp[],
    int ac[],
    int str[],
    int dex[],
    int con[],
    int num_monsters,
    char term[]){
    for (int i = 0; i < num_monsters; i++){
        if(strstr(names[i],term) != NULL){
            printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON", names[i], types[i], hp[i], ac[i], str[i], dex[i], con[i]);
        }
    }
    return 0;
}

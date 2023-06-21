#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"


void swap_int(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void parse_monster(monster_s *monster, char *csv_line) {
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token) {
        switch(attr) {
            case 0:
                strcpy(monster->name, token);
                break;
            case 1:
                strcpy(monster->type, token);
                break;
            case 2:
                monster->hp = atoi(token);
                break;
            case 3:
                monster->ac = atoi(token);
                break;
            case 4:
                monster->str = atoi(token);
                break;
            case 5:
                monster->dex = atoi(token);
                break;
            case 6:
                monster->con = atoi(token);
                break;
        }
        token = strtok(NULL, ",");
        attr++;
    }
}

void print_monster(monster_s monster){
    printf("\n%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON", monster.name, monster.type, monster.hp, monster.ac, monster.str, monster.dex, monster.con);
}

void print_dashes(int num_dashes){ 
    char dashes[MAX_LEN] = "-";  
    for(int i = 0; i < num_dashes-1; i++){
        strcat(dashes,"-");
    }
    trim(dashes);
    fprintf(stdout,"%s",dashes);
}

void print_monsters(monster_s *monsters_ptr, int num_monsters){
    /*
    int max_name_size = strlen(monsters_ptr[0].name);
    int max_type_size = strlen(monsters_ptr[0].type);
    int max_hp_size = log10(monsters_ptr[0].hp)+1;
    int max_ac_size = log10(monsters_ptr[0].ac)+1;
    int max_str_size = log10(monsters_ptr[0].str)+1;
    int max_dex_size = log10(monsters_ptr[0].dex)+1;
    int max_con_size = log10(monsters_ptr[0].con)+1;*/
    int max_name_size = 4 , max_type_size = 4, max_hp_size = 2, max_ac_size = 2, max_str_size = 3, max_dex_size = 3, max_con_size = 3;
    for(int i = 0; i < num_monsters; i++){
        if(strlen(monsters_ptr[i].name) > max_name_size){
            max_name_size=strlen(monsters_ptr[i].name);
        }
        if(strlen(monsters_ptr[i].type) > max_type_size){
            max_type_size=strlen(monsters_ptr[i].type);
        }
        if(log10(monsters_ptr[i].hp)+1 > max_hp_size){
            max_hp_size=log10(monsters_ptr[i].hp)+1;
        }
        if(log10(monsters_ptr[i].ac)+1 > max_ac_size){
            max_ac_size=log10(monsters_ptr[i].ac)+1;
        }
        if(log10(monsters_ptr[i].str)+1 > max_str_size){
            max_str_size=log10(monsters_ptr[i].str)+1;
        }
        if(log10(monsters_ptr[i].dex)+1 > max_dex_size){
            max_dex_size=log10(monsters_ptr[i].dex)+1;
        }
        if(log10(monsters_ptr[i].con)+1 > max_con_size){
            max_con_size=log10(monsters_ptr[i].con)+1;
        }
    }
    //char NAME[MAX_LEN] = "NAME";
    fprintf(stdout,"\n| %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s |", max_name_size, "NAME", max_type_size, "TYPE", max_hp_size, "HP", max_ac_size, "AC", max_str_size, "STR", max_dex_size, "DEX", max_con_size, "CON");
    fprintf(stdout,"\n| ");
    print_dashes(max_name_size);
    fprintf(stdout," | ");
    print_dashes(max_type_size);
    fprintf(stdout," | ");
    print_dashes(max_hp_size);
    fprintf(stdout," | ");
    print_dashes(max_ac_size);
    fprintf(stdout," | ");
    print_dashes(max_str_size);
    fprintf(stdout," | ");
    print_dashes(max_dex_size);
    fprintf(stdout," | ");
    print_dashes(max_con_size);
    fprintf(stdout," |");
    
    for(int i = 0; i < num_monsters; i++){
        fprintf(stdout,"\n| %-*s | %-*s | %-*d | %-*d | %-*d | %-*d | %-*d | ", max_name_size, monsters_ptr[i].name, max_type_size, monsters_ptr[i].type, max_hp_size, monsters_ptr[i].hp, max_ac_size, monsters_ptr[i].ac, max_str_size, monsters_ptr[i].str, max_dex_size, monsters_ptr[i].dex, max_con_size, monsters_ptr[i].con);
    }
    fprintf(stdout,"\n\n");
    //printf("| %-(max_name_size)f", NAME);
    //printf("\n%d %d %d %d %d %d %d",max_name_size,max_type_size,max_hp_size,max_ac_size,max_str_size,max_dex_size,max_con_size);

    //yes >:) unconventional method
    //char dashes[MAX_LEN] = "----------------------------------------------------------------------------------------------------------------------";
    //fprintf(stdout, "| NAME                 | TYPE     | HP  | AC | STR | DEX | CON |");
    //fprintf(stdout, "\n| %.(max_name_size)f-------------------- | -------- | --- | -- | --- | --- | --- |");
    //for(int i = 0; i < num_monsters; i++){
    //    fprintf(stdout, "\n%-(max_name_size+1)s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON", monster_ptr -> name, monster_ptr -> type, monster_ptr -> hp, monster_ptr -> ac, monster_ptr -> str, monster_ptr -> dex, monster_ptr -> con);
    //}
}

/*
 * Loads all monsters from a CSV file into memory.
 * Allocates memory pointed to by `*monsters_ptr`
 *
 * Args
 * ----
 *  monster_s **monsters_ptr - A double pointer to `monster_s`.
 *      Dereferencing this once (`*monsters_ptr`) returns the value to where the
 *      allocated memory should be stored. That is, you should assign the result
 *      of an allocation call to `*monsters_ptr`.
 *
 *  FILE *fp - A file pointer representing an open CSV file.
 *
 * Return
 * ------
 *  Returns an `int` representing the number of monsters loaded.
 */
int load_monster_csv(monster_s **monsters_ptr, FILE *fp) {
    char buffer[MAX_LEN] = { 0 };
    int num_read = 0;

    while (fgets(buffer, MAX_LEN, fp)) {
        trim(buffer);
        // Complete the function by parsing the csv line and storing the data into each monster_s entry.
        // For each item, you will need to reallocate the data to support 1 more.
        *monsters_ptr = realloc(*monsters_ptr, (num_read + 1) * sizeof(monster_s));
        parse_monster(*monsters_ptr + num_read, buffer);
        num_read++;
    }
    
    return num_read;
}

int comp_names(const void *elem1, const void *elem2){
   return (strcmp(((monster_s*)elem1) -> name, ((monster_s*)elem2)->name));
}
int comp_hp(const void *elem1, const void *elem2){
   return ((monster_s*)elem1)->hp - ((monster_s*)elem2)->hp;
}
int comp_ac(const void *elem1, const void *elem2){
   return ((monster_s*)elem1)->ac - ((monster_s*)elem2)->ac;
}
int comp_stats(const void *elem1, const void *elem2){
   return ((((monster_s*)elem1)->str+((monster_s*)elem1)->dex+((monster_s*)elem1)->con) - (((monster_s*)elem2)->str+((monster_s*)elem2)->dex+((monster_s*)elem2)->con));
}
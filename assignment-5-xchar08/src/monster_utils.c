#include "monster_utils.h"
#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Frees allocated memory of a monster.
 *
 */
void free_monster(void *monster) {
    // TODO: Cast the `void *monster` to the proper type and free
    //       all struct members that have allocated memory.
    if (monster != NULL) {
        monster_s *temp = monster;
        free(temp -> name);
        free(temp -> type);
        free(temp);
    }
}

/*
 * Prints the attributes of a single monster object.
 */
void print_monster(void *monster) {
    // TODO: Cast the `void *monster` to the proper type and print
    //       the attributes.
    monster_s* monster_new = monster;
    printf("\n%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON", monster_new -> name, monster_new -> type, monster_new -> hp, monster_new -> ac, monster_new -> str, monster_new -> dex, monster_new -> con);
}

/*
 * Creates a monster based on user input.
 */
monster_s *create_monster() {
    char buffer[BUF_SIZE] = { 0 };

    monster_s *m = calloc(1, sizeof(monster_s));

    printf("Enter a name: ");
    m->name = get_string();

    printf("Enter a type: ");
    m->type = get_string();

    printf("Enter HP: ");
    scanf("%d", &m->hp);

    printf("Enter AC: ");
    scanf("%d", &m->ac);

    printf("Enter STR: ");
    scanf("%d", &m->str);

    printf("Enter DEX: ");
    scanf("%d", &m->dex);

    printf("Enter CON: ");
    scanf("%d", &m->con);

    return m;
}

/*
 * Parses a line of CSV containing monster stats.
 */
monster_s *parse_monster(char *csv_line) {
    char *token = strtok(csv_line, ",");
    int attr = 0;

    monster_s *monster = calloc(1, sizeof(monster_s));

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

        attr++;
        token = strtok(NULL, ",");
    }

    return monster;
}

/*
 * Load monster data from a CSV file.
 *
 * Returns an `array_s` object containing the monsters loaded.
 */
array_s load_monsters_csv(FILE *fp) {
    array_s monsters = { 0 };
    char buffer[MAX_LEN] = { 0 };
    int num_read = 0;

    // TODO: Complete this function.
    while (fgets(buffer, MAX_LEN, fp)) {
        num_read++;
        trim(buffer);
        push_c(parse_monster(buffer), &monsters);
    }

    return monsters;
}

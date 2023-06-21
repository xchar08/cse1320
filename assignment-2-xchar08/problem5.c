#include <stdio.h>

#include "utils.h"

void show_menu() {
    printf("--------------------------\n");
    printf("|      MONSTER LIST      |\n");
    printf("--------------------------\n");
    printf("| 1. Filter by name      |\n");
    printf("| 2. Filter by HP        |\n");
    printf("| 3. Filter by AC        |\n");
    printf("| 4. Filter by stats     |\n");
    printf("| 5. Exit                |\n");
    printf("--------------------------\n");
}

int main(int argc, char *argv[]) {
    // TODO: Validate input arguments
    if(!argv[1]){
        printf("Arguments failed to verify.");
        return 2;
    }
    printf("Arguments verified.\n");
    trim(argv[1]);
    // TODO: Attempt to open file given by first command line argument
    FILE *fp = NULL;
    fp = fopen(argv[1],"r");
    if(!fp){
        printf("File failed to open.");
    }
    printf("File opened.\n");
    // TODO: Load monsters
    monster_s *monsters = NULL;
    int num_monsters = load_monster_csv(&monsters, fp);
    // Run menu loop
    int choice = 0;
    while (choice != EXIT_CHOICE) {
        show_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // TODO: Implement name filtering
                // TODO: Filter by name and print
                qsort(monsters, num_monsters, sizeof(monster_s), comp_names);
                print_monsters(monsters, num_monsters);
                break;
            case 2:
                // TODO: Implement HP filtering
                // TODO: Filter by HP and print
                qsort(monsters, num_monsters, sizeof(monster_s), comp_hp);
                print_monsters(monsters, num_monsters);
                break;
            case 3:
                // TODO: Implement AC filtering
                // TODO: Filter by AC and print
                qsort(monsters, num_monsters, sizeof(monster_s), comp_ac);
                print_monsters(monsters, num_monsters);
                break;
            case 4:
                // TODO: Implement stats filtering
                // TODO: Filter by stats and print
                qsort(monsters, num_monsters, sizeof(monster_s), comp_stats);
                print_monsters(monsters, num_monsters);
                break;
            case 5:
                if (fp) {
                    fclose(fp);
                }
                break;
        }
    }
    return 0;
}

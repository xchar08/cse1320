#include "utils.h"

int main(int argc, char** argv) {
    // TODO: Verify command line arguments.
    if(!argv[1]){
        printf("Arguments failed to verify.");
        return 2;
    }
    printf("Arguments verified.\n");
    // TODO: Attempt to open a CSV file given by the command line arguments.
    trim(argv[1]);
    FILE* file;
    file = fopen(argv[1],"r");
    if(!file){
        printf("File failed to open.");
    }
    printf("File opened.");
    // TODO: Load all the data with `load_monsters_csv`.
    // TODO: Print the data to verify that it was loaded.
    // TODO: Be sure to free any allocated memory.
    monster_s *monsters = NULL;
    int num_monsters = load_monster_csv(&monsters, file);  
    for(int i = 0; i < num_monsters; i++){
        print_monster(monsters[i]);
    }
    //print_monsters(monsters, num_monsters);
    return 0;
}

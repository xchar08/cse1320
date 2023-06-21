#include "monster_utils.h"
#include "hash_map_utils.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

void print_menu() {
    printf("1. Add Monster\n");
    printf("2. Import CSV File\n");
    printf("3. Search\n");
    printf("4. Print Map\n");
    printf("5. Exit\n");
}

hash_element_t monster2hashe(monster_s *m){  
    hash_element_t hash_e;
    hash_e.key=m->name;
    hash_e.value=m;

    return hash_e;
}

void reserve(hash_map_t map, int new_size) {
    // Resize and Rehash
    hash_element_t **temp_map = calloc(new_size, sizeof(void));

    for(int i = 0; i < map.map_size; i++) {
        hash_element_t *elem = map.primary[i];

        if(elem == NULL) {
            continue;
        }

        int index = compute_index(elem->key, new_size);
        int hash = hash_function(elem->key);
        int i = 1;

        while(temp_map[index] != NULL) {
            // Call your quadratic probing function to update index
            index = default_probe(hash, i) % map.map_size;
        }

        printf("Inserting %s at %d\n", elem->key, index);

        temp_map[index] = elem;
    }

    map.primary = temp_map;
    map.map_size = new_size;
    free(map.primary);
} 

void bulk_insert(hash_map_t *map, array_s elements) {
    // if the map is currently rehashing, dump the rest of the elements before reserving
    int num_keys = elements.numel;
    double new_size = bucket_size(elements.numel, LOAD_FACTOR);
    // Reserve enough space to accommodate adding all elements in the array.
    while(map->temp!=NULL){
        rehash_inc(map);
    }
    
    reserve(*map, new_size);
    for(int i = 0; i<map->map_size; i++){
        insert_no_rehash(map,elements.data[i]);
    }
    // The macro created earlier will compute this number.
    // Insert all elements into the map using `insert_no_rehash`.
}

// TODO: Create function to create an array of hash_element_t based on unique entries in array.
void add_monsters(hash_map_t *map, array_s monsters) {
    // Loop through `monsters` and check which of them are unique using `search`
    // For each unique monster, place it in a `hash_element_t` object using the monster's name as its key.
    // Add the array of `hash_element_t` objects to the hash map.
    array_s new_mon_array;
    for(int i = 0; i < monsters.numel; i++){
        hash_element_t mel = monster2hashe(monsters.data[i]);
        hash_element_t *mele = search(map, mel.key);
        if(mele==NULL){
            push_c(mele,&new_mon_array);
        }
        free_element(mele,free_monster);
    }
    bulk_insert(map, new_mon_array);
    
}

int main() {
    hash_map_t *map = calloc(1, sizeof(hash_map_t));
    char selection = 0;

    init_map(map, 4);

    while (selection != '5') {
        print_menu();
        printf("> ");
        scanf("%c", &selection);

        // Clear buffer if newline stuck.
        if (selection != '\n') while (getchar() != '\n');

        switch (selection) {
            case '1':{
                // TODO: Create a monster via `create_monster` and add it to the map.
                monster_s m = *create_monster();
                hash_element_t hash_e = monster2hashe(&m);
                hash_element_t *e = search(map,hash_e.key);
                //hash_element_t *search(hash_map_t *map, char *key) 
                if(e!=NULL){
                    free_element(e,free_monster);
                }else{
                    insert(map,&hash_e);
                }
                break;
            }
            case '2':{
                // TODO: Load a monsters via CSV.
                char line[MAX_LEN];
                fgets(line, MAX_LEN, stdin);
                trim(line);
                FILE *fp = NULL;
                fp = fopen(line,"r");
                if(!fp){
                    printf("File failed to open.");
                }
                printf("File opened.\n");
                array_s mon_array = load_monsters_csv(fp);
                add_monsters(map, mon_array);
                fclose(fp);
                free(fp);
                break;
            }
            case '3':{
                // TODO: Prompt the user for a search key and then call `search`
                char skey[MAX_LEN];
                fgets(skey, MAX_LEN, stdin);
                trim(skey);
                hash_element_t *new_s = search(map,skey);
                break;
            }
            case '4':{
                print_map(map, print_monster);
                break;
            }
            case '5':{
                printf("Good bye!\n");
                // TODO: Free all memory currently allocated.
                free_map(map,free_monster);
                break;
            }
            default:
                printf("Invalid selection.\n");
        }
    }

    return 0;
}

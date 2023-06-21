#include "problem1.h"

char* find_words(char *words[], char *key, int num_words){
    for(int i = 0; i < num_words; i++){
        if(strcmp(words[i], key) == 0){
            printf("Found \"%s\"", key);
            return key; 
        }
    }
    printf("Could not find \"%s\"", key);
    return NULL;
}
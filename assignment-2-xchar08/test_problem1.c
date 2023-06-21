#include "problem1.h"

int main(void){
    char *strings[] = {
    "string1",
    "string2",
    "string3",
    "string4"
    };
    char inp[MAX_LEN];
    printf("Enter a search term: ");
    fgets(inp, MAX_LEN, stdin);
    trim(inp);
    find_words(strings, inp, 4);
    
    return 0;
}
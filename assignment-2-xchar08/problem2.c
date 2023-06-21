#include "problem2.h"

int compare_int(const void *elem1, const void *elem2){
    if(*(int*)elem1%2!=0){
        if(*(int*)elem2%2!=0){
            return ( *(int*)elem1 - *(int*)elem2);
        }
        return -1;
    }
    if(*(int*)elem2%2!=0){
        return 1;
    }
    return ( *(int*)elem1 - *(int*)elem2);
}

int main(void){
    char inp[MAX_LEN];
    printf("Enter 10 values: ");
    fgets(inp, MAX_LEN, stdin);
    trim(inp);
    char *token = strtok(inp, " ");
    int vals[MAX_LEN];
    for(int i = 0; i < 10; i++){
        vals[i] = atoi(token);
        token = strtok(NULL, " ");  
        printf("%d ",vals[i]);
    }
    printf("\n");
    qsort(vals, 10, sizeof(int), compare_int);
    for(int i = 0; i < 10; i++){
        printf("%d ", vals[i]);
    }
}
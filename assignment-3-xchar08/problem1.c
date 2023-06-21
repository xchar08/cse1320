#include "stack_utils.h"
int main(int argc, char** argv){
        if(!argv[1]){
            printf("Arguments failed to verify.");
           return 2;
        }
        printf("Arguments verified.\n");
        trim(argv[1]);
        FILE* file;
        file = fopen(argv[1],"r");
        if(!file){
            printf("Invalid log file.");
        }
        printf("File opened.\n");

        mystack_t *stack = calloc(1, sizeof(mystack_t));
        char buffer[BUF_SIZE] = { 0 };
        while(fgets(buffer, BUF_SIZE, file) != NULL){
            if(strlen(buffer) > 2){
                trim(buffer);
                char *result = strstr(buffer, "()");
                if(result){
                    print_tabs(stack -> num_items);
                    fprintf(stdout,"%s\n",buffer);
                    char *cp = calloc(strlen(buffer) + 1, sizeof(char));
                    strcpy(cp, buffer);   
                    push(buffer, stack);
                } else if(strcmp(buffer,"return") == 0 ){
                    char *tmp = pop(stack);
                    free(tmp);
                }
            }
        }
        free(stack);
        fclose(file);
}
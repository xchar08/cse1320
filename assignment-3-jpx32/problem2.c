#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "queue_utils.h"

#define BUFSIZE 1024

int main() {
    int selection = 0;
    array_s queue = { 0 };
    player_s *temp = NULL;
    int position = 1;
    show_menu();
    while (selection != -1) {
        selection = atoi(get_string());
        switch (selection) {
            case 1:
                enqueue(create_player(get_string(), position), &queue);
                position++;
                break;
            case 2:
                rolld20(&queue);                
                break;
            case 3:
                temp = (player_s *)(dequeue(&queue));
                if (temp != NULL) {
                    peek(&queue);
                    fprintf(stdout,"%s is on deck.\n", ((player_s *)(temp)->name));
                    enqueue(temp, &queue);
                } else {
                    fprintf(stdout,"There are no items in the queue.\n");
                }
                break;
            case 4:
                print_queue(&queue);
                break;
            default:
                selection = -1;
                break;
        }
        show_menu();
    }
    free(temp);
    fprintf(stdout,"Queue has exited.");

    return 0;
}

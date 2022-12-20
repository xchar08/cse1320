#ifndef LL_TESTS_H_
#define LL_TESTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node Node;
struct node {
  void *data;
  Node *next;
};

Node *create_node(void *);
void insert_node(Node **, Node *, int);
void release(Node *n);

void linked_list_insert_sequential_start(int num_samples, int sample_size);
void linked_list_insert_sequential_end(int num_samples, int sample_size);
void linked_list_insert_random(int num_samples, int sample_size);

#endif // LL_TESTS_H_
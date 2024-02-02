#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdbool.h>

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

CircNode *Circnode_create(int val);
void Circnode_destroy(CircNode **cnode_ref);
CircList *CircList_create();
void CircList_destroy(CircList **CircList_ref);
bool CircList_is_empty(const CircList *L);
void CircList_add_first(CircList *L, int val);
void CircList_add_last(CircList *L, int val);
void CircList_print(const CircList *L);
void CircList_print_v2(const CircList *L);
void CircList_remove(CircList *L, int val);

#endif
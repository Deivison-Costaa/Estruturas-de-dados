#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct _node Node;
typedef struct _list List;

Node *Node_create(int val);
List *List_create();
void List_destroy(List **L_ref);
bool List_is_empty(const List *L);
void List_add_first(List *L, int val);
void List_add_last(List *L, int val);
void List_print(const List *L);
void List_inverted_print(const List *L);
void List_remove(List *L, int val);

#endif
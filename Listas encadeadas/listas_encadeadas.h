#ifndef LISTAS_ENCADEADAS_H
#define LISTAS_ENCADEADAS_H
#include <stdbool.h>
#include <stddef.h>



typedef struct snode SNode;
typedef struct linked_list LinkedList;

SNode *Snode_create(int val);

LinkedList *LinkedList_create();
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_destroy(LinkedList **L_ref);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);
void LinkedList_remove_test(LinkedList *L, int val);
void LinkedList_remove(LinkedList *L, int val);
void LinkedList_remove_all(LinkedList *L, int val);
size_t LinkedList_size_slow(const LinkedList *L);
size_t LinkedList_size(const LinkedList *L);
int LinkedList_first_val(const LinkedList *L);
int LinkedList_last_val(const LinkedList *L);
int LinkedList_get_val(const LinkedList *L, int index);

#endif
#include "CircList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _circ_node {
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
} CircNode;

typedef struct _circ_list {
    CircNode *begin;
    CircNode *end;
    size_t size;
} CircList;

CircNode *Circnode_create(int val){
    CircNode *cnode = (CircNode*) calloc(1, sizeof(CircNode));
    cnode->val = val;
    cnode->next = cnode;
    cnode->prev = cnode;

    return cnode;
}
void Circnode_destroy(CircNode **cnode_ref){
    CircNode *cnode = *cnode_ref;
    free(cnode);
    *cnode_ref = NULL;
}

CircList *CircList_create(){
    CircList *L = (CircList*) calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void CircList_destroy(CircList **CircList_ref){
    CircList *L = *CircList_ref;
    CircNode *p = L->begin;
    CircNode *aux = NULL;
    for(int i = 0; i < L->size; ++i){
        aux = p;
        p = p->next;
        Circnode_destroy(&aux);
    }
    free(L);
    *CircList_ref = NULL;
}

bool CircList_is_empty(const CircList *L){
    return L->size == 0;
}

// também é possível fazer da seguinte forma:
// while(p != L->end){
//     aux = p;
//     p = p->next;
//     Circnode_destroy(&aux);
// }
// Circnode_destroy(&p);

void CircList_add_first(CircList *L, int val){
    CircNode *p = Circnode_create(val);
    if(CircList_is_empty(L)){
        L->end = p;
    }else{
        p->next = L->begin;
        L->begin->prev = p;
        p->prev = L->end;
        L->end->next = p;
    }
    L->begin = p;
    L->size++;
}

void CircList_add_last(CircList *L, int val){
    CircNode *p = Circnode_create(val);

    if(CircList_is_empty(L)){
        L->begin = p;
    }else{
        L->end->next = p;
        p->prev = L->end;
        p->next = L->begin;
        L->begin->prev = p;
    }

    L->end = p;
    L->size++;
}

void CircList_print(const CircList *L){
    if(CircList_is_empty(L)){
        printf("L -> NULL\n");
        printf("L->end = NULL");
    }else{
        CircNode *p = L->begin;
        printf("L -> ");
        do{
            printf("%d -> ", p->val);
            p = p->next;
        }while(p != L->begin);
        printf("L -> end = %d", L->end->val);
    }
    printf("Size: %lu", L->size);
}
void CircList_print_v2(const CircList *L){
    if(CircList_is_empty(L)){
        printf("L -> NULL\n");
        printf("L->end = NULL");
    }else{
        CircNode *p = L->begin;
        printf("L -> ");
        for(int i = 0; i < L->size; ++i){
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("\nL -> end = %d", L->end->val);
    }
    printf("\nSize: %lu\n\n", L->size);
}

void CircList_remove(CircList *L, int val){
    if(!CircList_is_empty(L)){
        if(L->begin->val == val){
            CircNode *p = L->begin;

            if(L->begin == L->end){
                L->begin = L->end = NULL;
            }else{
                L->begin = p->next;
                L->begin->prev = L->end;
                L->end->next = L->begin;
            }
            Circnode_destroy(&p);
            L->size--;
        }else{
            CircNode *p = L->begin->next;

            while(p != L->begin){
                if(p->val == val){
                    if(L->end == p){

                    }else{
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                    }
                    Circnode_destroy(&p);
                    L->size--;
                }else{
                    p = p->next;
                }
            }
        }
    }
}
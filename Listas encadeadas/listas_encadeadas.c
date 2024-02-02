#include <stdio.h>
#include <stdlib.h>
#include "listas_encadeadas.h"
#include <stdbool.h>


typedef struct snode
{
    int val;
    struct snode *next;
} SNode;

typedef struct linked_list
{
    SNode *begin;
    SNode *end;
    size_t size;
} LinkedList;

bool LinkedList_is_empty(const LinkedList *L){
    return (L->size == 0);
}

LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void LinkedList_destroy(LinkedList **L_ref){
    LinkedList *L = *L_ref;

    SNode *p = L->begin;
    SNode *aux = NULL;

    while(p){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

SNode *Snode_create(int val){
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

//void LinkedList_add_first(LinkedList *L, int val){
//    
//    SNode *p = Snode_create(val);
//    p->next = L->begin;
//    L->begin = p;
//    L->size++;
//}

void LinkedList_add_first(LinkedList *L, int val){
    
    SNode *p = Snode_create(val);
    p->next = L->begin;
    if(LinkedList_is_empty(L)){
        L->end = p;
    }
    L->begin = p;
    L->size++;
}

void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = Snode_create(val);
    if(LinkedList_is_empty(L)){
       L->begin = L->end = q;
    }else{
        L->end->next = q;
        L->end = L->end->next;
    }
    L->size++;
}

void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *q = Snode_create(val);
    if(LinkedList_is_empty(L)){
        L->begin = q;        
    }else{
        SNode *p = L->begin;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
    L->size++;
}

void LinkedList_remove_test(LinkedList *L, int val){
    if(!LinkedList_is_empty(L)){
        if(L->begin->val == val){
            SNode *pos = L->begin;
            if(L->begin == L->end){
                L->end = NULL;
            }
            L->begin = L->begin->next;
            free(pos);
            L->size--;
        }else{
            SNode *prev = L->begin;
            SNode *pos = L->begin->next;

            while(pos != NULL && pos->val != val){
                prev = prev->next;
                pos = pos->next;
            }
            if(pos != NULL){
                prev->next = pos->next;
            
                if(pos->next == NULL){
                L->end = prev;
                }
                free(pos);
                L->size--;
            }
        }
    }
}

void LinkedList_remove(LinkedList *L, int val){
    if(!LinkedList_is_empty(L)){
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while(pos != NULL && pos->val != val){
            prev = pos;
            pos = pos->next;
        }
        if(pos){
            if(L->end == pos){
                L->end = prev;
            }
            if(L->begin == pos){
                L->begin = pos->next;
            }else{
                prev->next = pos->next;
            }
            free(pos);
            L->size--; 
        }   
    }
}

void LinkedList_remove_all(LinkedList *L, int val){
    if(!LinkedList_is_empty(L)){
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while(pos){
            SNode *aux = pos;
            if(pos->val == val){
                if(L->end == pos){
                    L->end = prev;
                }
                if(L->begin == pos){
                    L->begin = pos->next;
                }else{
                    prev->next = pos->next;
                }
                aux = pos;
                pos = pos->next;
                free(aux);
                L->size--;
            }else{
                prev = pos;
                pos = pos->next;
            }
        }
    }
}

 
void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;
    printf("List -> ");
    while(p != NULL){
        printf("%d - > ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    if(L->end != NULL){
        printf("End: %d\n", L->end->val);
    }else{
        printf("End: NULL\n");
    }
    printf("Size: %lu\n", L->size);
}

// size_t LinkedList_size_slow(const LinkedList *L){
//     size_t size;
//     SNode *p = L->begin;
//     while(p != NULL){
//         ++size;
//         p = p->next;
//     }
//     return size;
// }

size_t LinkedList_size_slow(const LinkedList *L){
    size_t size;
    for(SNode *p = L->begin; p != NULL; p = p->next){
        ++size;
    }
    return size;
}

size_t LinkedList_size(const LinkedList *L){
    return L->size;
}

int LinkedList_first_val(const LinkedList *L){
    if(LinkedList_is_empty(L)){
        printf("A lista esta vazia");
        exit(EXIT_FAILURE);
    }else{
        return L->begin->val;
    }
}
int LinkedList_last_val(const LinkedList *L){
    if(LinkedList_is_empty(L)){
        printf("A lista esta vazia");
        exit(EXIT_FAILURE);
    }else{
        return L->end->val;
    }
}
//consideramos a contagem a partir de 0.
int LinkedList_get_val(const LinkedList *L, int index){
    if(LinkedList_is_empty(L)){
        printf("A lista esta vazia.");
        exit(EXIT_FAILURE);
    }else if(index < 0 || index >= L->size){
        printf("index invalido.");
        printf("\nTente entre os indices [0, %lu]", L->size - 1);
        exit(EXIT_FAILURE);
    }else{
        SNode *p = L->begin;
        for(int i = 0; i != index; ++i){
            p = p->next;
        }
        return p->val;
    }
}

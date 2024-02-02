#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct snode
{
    int val;
    struct snode *next;
} SNode;

typedef struct linked_list
{
    SNode *begin;
    SNode *end;
} LinkedList;

bool LinkedList_is_empty(const LinkedList *L){
    return (L->begin == NULL && L->end == NULL);
}

LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
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
//}

void LinkedList_add_first(LinkedList *L, int val){
    
    SNode *p = Snode_create(val);
    p->next = L->begin;
    if(LinkedList_is_empty(L)){
        L->begin = L->end = p;
    }
    L->begin = p;
}

void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = Snode_create(val);
    if(LinkedList_is_empty(L)){
       L->begin = L->end = q;
    }else{
        L->end->next = q;
        L->end = L->end->next;
    }
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
}

void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;
    printf("List -> ");
    while(p != NULL){
        printf("%d - > ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}



int main(void){


    LinkedList *L = LinkedList_create();
    FILE *arquivo = fopen("resultados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }
    time_t inicio, fim;

    int i;
    fprintf(arquivo, "num,time\n");
    for(i = 0; i < 100000; ++i){
        inicio = clock();
        LinkedList_add_last_slow(L, i);
        fim = clock();
        fprintf(arquivo,"%d,%f\n", i,(float)(fim-inicio)/CLOCKS_PER_SEC);
    }

    fclose(arquivo);

/*
    LinkedList_add_first(L, 5);
    LinkedList_print(L);
    LinkedList_add_first(L, 6);
    LinkedList_print(L);
    LinkedList_add_first(L, 2);
    LinkedList_print(L);
    LinkedList_add_first(L, 1);
    LinkedList_print(L);
    LinkedList_add_first(L, 9);
    LinkedList_print(L);
    LinkedList_add_last(L, 20);
    LinkedList_print(L);
    LinkedList_add_last(L, 14);

    LinkedList_print(L);
*/

    return 0;
}
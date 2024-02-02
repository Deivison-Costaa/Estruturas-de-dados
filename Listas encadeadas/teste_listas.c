#include <stdio.h>
#include <stdlib.h>
#include "listas_encadeadas.h"

int main(void){
    LinkedList *L = LinkedList_create();
    LinkedList_add_first(L, 23);
    LinkedList_print(L);
    LinkedList_add_first(L, 34);
    LinkedList_print(L);
    LinkedList_add_first(L, 65);
    LinkedList_print(L);
    LinkedList_add_first(L, 13);
    LinkedList_print(L);
    LinkedList_add_first(L, 97);
    LinkedList_print(L);
    LinkedList_add_first(L, 76);
    LinkedList_print(L);
    LinkedList_add_first(L, 67);
    LinkedList_print(L);
    LinkedList_add_first(L, 87);
    LinkedList_print(L);
    LinkedList_add_last(L, 23);
    LinkedList_print(L);
    LinkedList_add_last(L, 55);
    LinkedList_print(L);
    LinkedList_add_last(L, 98);
    LinkedList_print(L);
    LinkedList_add_last(L, 98);
    LinkedList_print(L);
    LinkedList_add_last(L, 98);
    LinkedList_print(L);
    LinkedList_add_last(L, 98);
    LinkedList_print(L);
    LinkedList_add_last(L, 98);
    LinkedList_print(L);
    LinkedList_add_last(L, 98);
    LinkedList_print(L);
    LinkedList_remove_all(L, 98);
    LinkedList_print(L);
    printf("value [0]: %d\n", LinkedList_get_val(L,0));
    printf("value [2]: %d\n", LinkedList_get_val(L,2));
    printf("value [4]: %d\n", LinkedList_get_val(L,4));
    printf("value [6]: %d\n", LinkedList_get_val(L,6));
    printf("value [7]: %d\n", LinkedList_get_val(L,7));
    LinkedList_destroy(&L);

    return 0;
}
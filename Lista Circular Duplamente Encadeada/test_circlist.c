#include "CircList.h"
#include <stdio.h>

int main(void){
    CircList *L = CircList_create();

    CircList_add_first(L, 5);
    CircList_add_first(L, 8);
    CircList_add_first(L, 7);
    CircList_add_first(L, 4);
    CircList_add_first(L, 2);
    CircList_add_first(L, 1);
    CircList_add_first(L, 9);
    CircList_add_first(L, 0);
    CircList_print_v2(L);

    CircList_remove(L, 0);
    CircList_print_v2(L);


    CircList_destroy(&L);
}
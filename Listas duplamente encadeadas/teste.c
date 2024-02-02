#include "list.h"
#include <stdio.h>

int main(void){
    List *L;
    L = List_create();
    List_add_first(L, 10);
    List_print(L);
    List_add_first(L, 5);
    List_print(L);
    List_add_first(L, 2);
    List_print(L);
    List_add_last(L,17);
    List_print(L);

    printf("remove 13\n");
    List_remove(L,13);
    List_print(L);
    printf("remove 5\n");
    List_remove(L,5);
    List_print(L);
    printf("remove 17\n");
    List_remove(L,17);
    List_print(L);
    List_remove(L,2);
    List_print(L);
    List_remove(L,10);
    List_print(L);
    printf("ttt");
    List_remove(L,45);
    List_print(L);


    List_destroy(&L);
}
#include <stdio.h>
#include "clases_listas.h"
void print_list(tList L){
    tPosL p;

    printf("(");
    if(!isEmptyList(L)){
        for(p= first(L); p != LNULL; p= next(p, L))
            printf(" %d ", getItem(p,L));
    }
    printf(")\n");
}
int main() {
    tList L; tPosL p;

    createEmptyList(&L);

    insertItem(1,LNULL, &L);
    print_list(L);
    insertItem(3,LNULL, &L);
    print_list(L);
    insertItem(2,next(first(L),L),&L);
    print_list(L);
    insertItem(4,LNULL, &L);
    print_list(L);

    return 0;
}

#include <stdio.h>
#include "listas_punteros.h"
int main() {
    printf("Hello, World!\n");
    return 0;
}

int count_elements(tList L){
    tPosL p;
    int count = 0;

    if(!isEmptyList(L)){
        for(p = first(L); p != LNULL; count++, p = next(p, L));
    }
    return count;
}

bool equal_list(tList L, tList M) {
    tPosL p, q;

    if (isEmptyList(L) && isEmptyList(M)) {
        return true;
    } else if (isEmptyList(L) || isEmptyList(M)) {
        return false;
        // }else if(last(L) != last(M)) { //No es eficiente recorrer toda la lista(en la función las se recorre toda
        //   return false;
    } else {
        for (p = first(L), q = first(M);
             (p != LNULL) && (q != LNULL) && (getItem(p, L) == getItem(p, M)); p = next(p, L), q = next(q, M));
        return (p == LNULL) && (q == LNULL);
    }
}

void print_list(tList L){
    tPosL p;

    printf("(");
    if(!isEmptyList(L)){
     for( p = first(L); p != LNULL; p = next(p,L)){
         printf(" %d ", getItem(p, L));
     }
    }
    printf(")\n");
}

void print_list_inverse(L){
    tPosL p;

    printf("(");
    if(!isEmptyList(L)){
        for( p = last(L); p != LNULL; p = previous(p,L)){
            printf(" %d ", getItem(p, L));
        }
    }
    printf(")\n");
}

int count_ocurrences(tItemL i, tList L){
    int count = 0;
    tPosL p;

    if(!isEmptyList(L)){
        for(p = first(L); p != LNULL; p = next(p,L)){
            if(getItem(p, L) == 1){
                count ++;
            }
        }
    }
}

bool equal_sets(tList L, tList M){
    tPosL p,q;
    if (isEmptyList(L) && isEmptyList(M)) {
        return true;
    } else if (isEmptyList(L) || isEmptyList(M)) {
        return false;
    }else if(count_elements(L) != count_elements(M)){
        return false;
    } else {
        for (p = first(L); p != LNULL ; p = next(p,L)){
            for(q = first(M); q!=LNULL && (getItem(p,L) != getItem(q,M)); q= next(q,L));
                if(q==LNULL){
                    return false;
                }
        }
        return true;
    }
}





//
// Created by Usuario on 06/02/2024.
//

#include "clases_listas.h"

void createEmptyList(tList* L){
    L->lastPos = LNULL; //(*L).lastPos = LNULL;

}

bool insertItem(tItemL d, tPosL p, tList* L){
    tPosL q;

    if(L->lastPos == MAX - 1)
        return false;
    else{
        L->lastPos++;
        if(p == LNULL)
            L->data[L->lastPos] = d;
        else{
            for(q = L->lastPos; q>p; q--)
                L->data[q] = L->data[q-1];
            L->data[q] = d;
        }
        return true;
    }
}

bool copyList(tList L, tList * M){
    tPosL p;

    createEmptyList(M); //copyList(L,&M) en el main al usarla
    if (L.lastPos != LNULL){
        for(p=0; p<=L.lastPos; p++){
            M-> data[p] = L.data[p];//(*M).data[p]= L.data[p];
        }
        M-> lastPos = L.lastPos;
    }
    return true;
}

void updateItem(tItemL d, tPosL p, tList * L){
    L-> data[p] = d;
}

tPosL findItem(tItemL d, tList L){
    tPosL p;

    if(L.lastPos == LNULL){
        return LNULL;
    }else{
        for(p=0; p<L.lastPos && (L.data[p] != d) ;p++){
            if(L.data[p] == d){
                return p;
            }else{
                return LNULL;
            }
        }
    }
}

bool isEmptyList(tList L){
    return L.lastPos == LNULL;
}

tItemL getItem(tPosL p, tList L){
    return L.data[p];
}

tPosL first(tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL next(tPosL p, tList L){
    if(p==L.lastPos)
        return LNULL;
    else
        return p+1; // ++p
}

tPosL previous(tPosL p, tList L){
    if(p==0)
        return LNULL;
    else
        return p-1;//p--
}

void deleteAtPosition(tPosL p, tList * L){
    tPosL q;

    for(q=p; q<L->lastPos; q++){
        L->data[q] = L->data[q+1];
    }
    L->lastPos--;
}

void deleteList(tList * L){
   // while (!isEmptyList(*L))
     //   deleteAtPosition(last(*L),L);
     L->lastPos = LNULL;
}

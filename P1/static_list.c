/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */
#include "static_list.h"
#include <string.h>

void createEmptyList(tList* L){
    L->lastPos = LNULL;
}

bool isEmptyList(tList L){
    return L.lastPos == LNULL;
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
        return ++p;
}

tPosL previous(tPosL p, tList L){
    if(p==0)
        return LNULL;
    else
        return --p;
}
bool insertItem(tItemL Item, tPosL p, tList* L){
    tPosL q;
    if(L->lastPos == MAX - 1)
        return false;
    else{
        L->lastPos++;
        if(p == LNULL)
            L->Item[L->lastPos] = Item;
        else{
            for(q = L->lastPos; q>p; q--)
                L->Item[q] = L->Item[q-1];
            L->Item[q] = Item;
        }
        return true;
    }
}
void deleteAtPosition(tPosL p, tList* L){
    tPosL q;
    for(q=p; q<L->lastPos; q++){
        L->Item[q] = L->Item[q+1];
    }
    L->lastPos--;
}

tItemL getItem(tPosL p, tList L){
    return L.Item[p];
}

void updateItem(tItemL Item, tPosL p, tList* L){
    L->Item[p] = Item;
}

tPosL findItem(tUserName name, tList L){
    if(L.lastPos == LNULL){
        return LNULL;
    }else{
        for (tPosL p = 0; p <= L.lastPos; ++p) {
            if (strcmp(name, L.Item[p].userName) == 0) {
                return p;
            }
        }
        return LNULL;
    }
}

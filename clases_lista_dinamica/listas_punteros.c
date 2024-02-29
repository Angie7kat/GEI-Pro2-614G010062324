//
// Created by Usuario on 23/02/2024.
//

#include "listas_punteros.h"
#include <stdlib.h>
void createEmptyList(tList* L){
    *L = LNULL;
}
bool createNode(tPosL* p){
    *p = malloc(sizeof (struct tNode));
    return *p != LNULL;
}
bool insertItem(tItemL d, tPosL p, tList* L){
    tPosL q, r;

    if(!createNode(&q)){
        return false;
    }else{
        q->data = d;
        q->next = LNULL;
        if(*L == LNULL){
            *L = q;
        }else if(p == LNULL){
            for(r = *L; r -> next != LNULL; r = r -> next);
            r -> next = q;
        }else if(p == *L){
            q -> next = p;
            *L = q;
        }else{
            q -> data = p-> data;
            p -> data = d;
            q -> next = p -> next;
            p -> next = q;
        }

        return true;
    }
}

bool copyList(tList L, tList * M){
    tPosL p, q, r;
    bool ret = true;

    createEmptyList(M);
    if(!isEmptyList(L)){
        p = L;
        while((p!= LNULL) && createNode(&r)){
            r->data = p->data;
            r->next = LNULL;
            if(p == L){
                *M = r;
                q = r;
            }else{
                q->next = r;
                q = r;
            }
            p = p->next;
        }
        if(p != LNULL){
            deleteList(M);
            ret = false;
        }
    }
    return ret;
}

void updateItem(tItemL d, tPosL p, tList * L){
    p->data = d;
}

tPosL findItem(tItemL d, tList L){
    tPosL p;

    for(p=L; (p != LNULL) && (p->data != d); p = p->next);
    return p;
}

bool isEmptyList(tList L){
    return L == LNULL;
}

tItemL getItem(tPosL p, tList L){
    return p->data;
}

tPosL first(tList L){
    return L;
}

tPosL last(tList L){
    tPosL p;
    for(p=L; p->next != LNULL; p= p->next);
    return p;
}

tPosL next(tPosL p, tList L){
    return p->next;
}

tPosL previous(tPosL p, tList L){
    tPosL q;

    if(p == L){
        return LNULL;
    }else{
        for( q = L; q-> next != p; q = q->next);
        return q;
    }
}

void deleteAtPosition(tPosL p, tList * L){

}

void deleteList(tList * L){

}
//
// Created by Usuario on 19/03/2024.
//

#include "nose.h"

tPosL findPosition(tList L, tItemL d){
    tPosL p;

    p=L;
    while((p->next != LNULL) && (p->next->data < d))
        p = p->next;
    return p;
}
bool insertItem2(tItemL d, tList* L){
    tPosL q,p;

    if(!createNode(&q))
        return false;
    else{
        q->data = d;
        q->next = LNULL;

        if(*L == LNULL)
            *L = q;
        else if(d < (*L)->data){
            q->next = *L;
            *L = q;
        }else{
            p = findPosition(*L, d);
            q->next = p -> next;
            p -> next = q;
        }
    }
}
//LISTA CRECIENTE
tPosL finditem2(tItemL d, tList L){
    tPosL p;
    for(p=L;(p != LNULL) && (p->data < d); p= p->next);
    if((p != LNULL) && (p->data ==d))
        return p;
    else
        return LNULL;
}
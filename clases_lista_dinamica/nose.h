//
// Created by Usuario on 19/03/2024.
//

#ifndef CLASES_LISTA_DINAMICA_NOSE_H
#define CLASES_LISTA_DINAMICA_NOSE_H
#include <stdbool.h>
#define LNULL NULL
typedef int tItemL;
typedef struct tNode* tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

void createEmptyList(tList* L);
bool insertItem(tItemL d, tPosL p, tList* L);
bool copyList(tList L, tList * M);
void updateItem(tItemL d, tPosL p, tList * L);
tPosL findItem(tItemL d, tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL next(tPosL p, tList L);
tPosL previous(tPosL p, tList L);
void deleteAtPosition(tPosL p, tList * L);
void deleteList(tList * L);

#endif //CLASES_LISTA_DINAMICA_NOSE_H

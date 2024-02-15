//
// Created by Usuario on 06/02/2024.
//

#ifndef CLASE_LISTAS_CLASES_LISTAS_H
#define CLASE_LISTAS_CLASES_LISTAS_H
#include <stdbool.h>
/*Definiciones de tipo */

#define LNULL -1
#define MAX 100

typedef int tItemL;
typedef int tPosL;
typedef struct{
    tItemL data[MAX];
    tPosL lastPos;
} tList;
/* Prototipos de operaciones/funciones*/
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

#endif //CLASE_LISTAS_CLASES_LISTAS_H

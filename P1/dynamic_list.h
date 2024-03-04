/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <stdbool.h>
#define LNULL NULL

#include "types.h"

typedef int tItemL;
typedef struct tNode* tPosL;
struct tNodo{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

void createEmptyList(tList* L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
bool isEmptyList(tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL first(tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL last(tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL next(tPosL p, tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL previous(tPosL p, tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
bool insertItem(tItemL d, tPosL p, tList* L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
void deleteAtPosition(tPosL p, tList * L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tItemL getItem(tPosL p, tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
void updateItem(tItemL d, tPosL p, tList * L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL findItem(tItemL d, tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */

// Estas se definen en teoría y NO salen en el enunciado
bool copyList(tList L, tList * M);
void deleteList(tList * L);

#endif

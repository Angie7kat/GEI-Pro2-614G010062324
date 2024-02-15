/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#define MAX 25
#define LNULL -1

#include "types.h"

typedef int tPosL;
typedef struct{
    tPosL lastPos;
    tItemL Item[MAX];
}tList;

void createEmptyList (tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
bool isEmptyList (tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL first (tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL last (tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL next (tPosL, tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL previous (tPosL, tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
bool insertItem (tItemL, tPosL, tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
void deleteAtPosition (tPosL, tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tItemL getItem (tPosL, tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
void updateItem (tItemL, tPosL, tList);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
tPosL findItem (tUserName d, tList L);
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */

#endif

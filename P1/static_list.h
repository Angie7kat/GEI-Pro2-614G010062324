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
 *
 */
bool isEmptyList (tList);
/*
 *
 */
tPosL first (tList);
/*
 *
 */
tPosL last (tList);
/*
 *
 */
tPosL next (tPosL, tList);
/*
 *
 */
tPosL previous (tPosL, tList);
/*
 *
 */
bool insertItem (tItemL, tPosL, tList);
/*
 *
 */
void deleteAtPosition (tPosL, tList);
/*
 *
 */
tItemL getItem (tPosL, tList);
/*
 *
 */
void updateItem (tItemL, tPosL, tList);
/*
 *
 */
tPosL findItem (tUserName d, tList L);
/*
 *
 */

#endif

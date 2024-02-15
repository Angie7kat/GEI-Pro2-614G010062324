/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
typedef int tPosL;
typedef struct{
    tPosL Pos;
    tItemL Item[MAXITEMS];
}tList;
void createEmptyList (tList);

bool isEmptyList (tList) → bool

tPosL first (tList) → tPosL

last (tList) → tPosL

next (tPosL, tList) → tPosL

previous (tPosL, tList) → tPosL

insertItem (tItemL, tPosL, tList) → tList, bool

deleteAtPosition (tPosL, tList) → tList

getItem (tPosL, tList) → tItemL

updateItem (tItemL, tPosL, tList) → tList

findItem (tUserName, tList) → tPosL

#endif

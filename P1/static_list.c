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
    /*Asignamos un valor nulo a la ultima posicion que hemos creado*/
}

bool isEmptyList(tList L){
    return L.lastPos == LNULL;
    /*A partir del valor de la ultima posicion creada, devuelve verdadero si es un valor nulo, y falso si tiene un valor no nulo*/
}

tPosL first(tList L){
    return 0;
    /*Devuelve el numero de la primera posicion en la lista*/
}

tPosL last(tList L){
    return L.lastPos;
    /*Devuelve el numero de la ultima posicion en la lista*/
}

tPosL next(tPosL p, tList L){
    if(p==L.lastPos)
        return LNULL;
    /*Creamos un condicional que determina si el valor dado es el ultimo de la lista. Si es asi devuelve un valor nulo*/
    else
        return ++p;
    /*En caso de que no sea el ultimo valor creado, se aumenta en 1 el valor dado*/
}

tPosL previous(tPosL p, tList L){
    if(p==0)
        return LNULL;
    /*Creamos un condicional que determina si el valor dado es el primero de la lista. Si es asi devuelve un valor nulo*/
    else
        return --p;
    /*A diferencia de la funcion next, si el valor el primero de la lista, se disminuye en 1 el valor dado*/
}
bool insertItem (tItemL Item, tPosL p, tList* L) {
    tPosL q;
    /*Creamos una variable auxiliar para recorrer el bucle*/
    if (L->lastPos == MAX - 1)
        return false;
    /*Creamos un condicional para comprobar si el valor dado puede insertarse en la posicion dada.
     *En caso de que la lista este llena, devuelve falso*/
    else{
        L->lastPos++;
        /*Si la lista no esta llena, aumentamos en 1 el valor de la ultima posicion*/
        if(p == LNULL)
            L->Item[L->lastPos] = Item;
            /*Creamos otro condicional para saber si el valor de p es nulo y posteriormente insertar el Item dado*/
        else {
            for(q = L->lastPos; q>p; q--)
                /*En caso de no ser nulo, creamos un bucle para recorrer la lista desde la ultima posicion creada*/
                L->Item[q] = L->Item[q-1];
                /*A cada posicion recorrida por la lista le asignamos el valor de la posicion anterior a ella*/
                L->Item[q] = Item;
                /*Finalmente */
        }
        return true;
    }
}
void deleteAtPosition(tPosL p, tList* L){
    tPosL q;
    /*Creamos una variable auxiliar para recorrer un bucle*/
    for(q=p; q<L->lastPos; q++){
        /*Creamos una lista que a partir del valor dado, y mientras el valor sea
         * menor que la ultima posicion creada, aumentamos en 1 su valor*/
        L->Item[q] = L->Item[q+1];
        /*A partir del valor dado, asignamos al valor por el que
         * pasa la lista el valor siguiente, para asi eliminar el valor asignado a la posicion dada*/
    }
    L->lastPos--;
    /*Finalmente disminuimos en 1 el valor del tamano de la lista*/
}

tItemL getItem(tPosL p, tList L){
    return L.Item[p];
    /*Devuelve el contenido en la posicion dada*/
}

void updateItem(tItemL Item, tPosL p, tList* L){
    L->Item[p] = Item;
    /*Cambiamos el contenido de la posicion dada por otro valor dado*/
}

tPosL findItem(tUserName name, tList L){
    tPosL p;
    /*Creamos una variable auxiliar para recorrer un bucle*/
    if(L.lastPos == LNULL){
        return LNULL;
        /*Creamos un condicional que devuelve nulo si la ultima posicion creada tiene valor nulo*/
    }else{
        for(p = 0; p <= L.lastPos; ++p){
            /*En caso de que no sea nulo, creamos un bucle desde 0 hasta la ultima posicion creada*/
            if (strcmp(name, L.Item[p].userName) == 0) {
                return p;
                /*Finalmente creamos un condicional que se asegura de que el contenido
                 * del nombre en la posicion del bucle sea igual al nombre dado*/
            }
        }
        return LNULL;
        /*En caso de que no coincida con ninguna posicion, devuelve nulo*/
    }
}

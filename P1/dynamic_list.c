/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyList(tList* L){
    *L = LNULL;
    /* Creamos una lista vacía asignándole un valor NULL al puntero lista.*/
}

/* Función que crea nodos que son necesarios para operar en la lista, ya que esta funciona por nodos.*/
bool createNode(tPosL* p){
    *p = malloc(sizeof(struct tNode));
    return *p != LNULL;
    /* Devuelve true si el nodo ha sido creado correctamente.*/
}

bool isEmptyList(tList L){
    return L == LNULL;
    /* Devuelve true si la lista está vacía y false si no lo está.*/
}

tPosL first(tList L){
    return L;
    /* Devolvemos la primera posición de la lista.*/
}

tPosL last(tList L){
    tPosL p;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    for(p=L; p->next != LNULL; p = p->next);
    return p;
    /* Creamos un bucle para recorrer la lista y llegar a la última posición para al final devolverla.*/
}

tPosL next(tPosL p, tList L){
    return p->next;
    /* Devolvemos la posición siguiente de la indicada; a diferencia de la estática aquí el último puntero apunta a
     * null así que no es necesario hacer un filtro.*/
}

tPosL previous(tPosL p, tList L){
    tPosL q;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    if(p == L){
        return LNULL;
        /* Si la posición indicada es la primera no hay previo, devolvemos nulo.*/
    }else{
        /* En caso contrario debemos recorrer la lista hasta esa posición.*/
        for(q = L; q->next != p; q = q->next);
        return q;
        /* El bucle lo recorremos hasta justo la posición anterior a la que se indica (q->next != p) y así ya tenemos
         * directamente el valor previo.*/
    }
}

bool insertItem(tItemL d, tPosL p, tList* L) {
    tPosL q, r;
    /* Creamos dos variables auxiliares, una para ayudarnos a insertar el item y el otro para recorrer la lista.*/
    if (!createNode(&q)) {
        return false;
        /* Primero comprobamos si se puede crear un nodo para insertar el item, si no se puede devolvemos falso, no se
         * ha podido insertar el item.*/
    } else {
        q->data = d;
        q->next = LNULL;
        if (*L == LNULL) {
            *L = q;
        } else if (p == LNULL) {
            for (r = *L; r->next != LNULL; r = r->next);
            r->next = q;
        } else if (p == *L) {
            q->next = p;
            *L = q;
        } else {
            q->data = p->data;
            p->data = d;
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList * L){
    tPosL q;

    if(p == *L){
        *L = (*L) -> next;
    }else if(p->next == LNULL){ //ultima pos
        for(q = *L; q ->next != p; q = q ->next);
        q->next = LNULL;
    }else{
        q = p-> next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }
    free(p);
}

tItemL getItem(tPosL p, tList L){
    return p->data;
    /* De volvemos la data de la posición indicada.*/
}

void updateItem(tItemL d, tPosL p, tList * L){
    p->data = d;
    /* Actualizamos el valor en p->data.*/
}

tPosL findItem(tUserName name, tList L){
    tPosL p;
    /* Creamos una variable auxilar que nos ayudará con el bucle.*/
    for(p = L; (p != LNULL) && (strcmp(p->data.userName, name) != 0); p = p->next);
    /* Recorremos la lista comparando el nombre introducido con los de la lista hasta encontrar la posición en la que
     * está.*/
        if (p == LNULL || strcmp(p->data.userName,name) != 0){
            return LNULL;
            /* Si hemos llegado al final sin encontrar el name devolvemos un nulo, no ha sido posible encontrar la
             * posición o no está ese valor en la lista.*/
        }
    return p;
        /* Si lo hemos encontrado devolvemos la posición en la que está.*/
}

/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */

#include "user_list.h"
#include "song_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyListU(tListU *L){
    *L = NULLU;
    /* Creamos una lista vacía asignándole un valor NULL al puntero lista.*/
}
/* Función que crea nodos que son necesarios para operar en la lista, ya que esta funciona por nodos.*/
bool createNodeU(tPosU *p){
    *p = malloc(sizeof(struct tNode));
    return *p != NULLU;
}

bool isEmptyListU(tListU L){
    return (L == NULLU);
    /* Devuelve true si la lista está vacía y false si no lo está.*/
}

tPosU firstU(tListU L){
    return L;
    /* Devolvemos la primera posición de la lista.*/
}

tPosU lastU(tListU L){
    tPosU p;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    for (p = L; p->next != NULLU; p = p->next);
    return p;
    /* Creamos un bucle para recorrer la lista y llegar a la última posición para al final devolverla.*/
}

tPosU nextU(tPosU p, tListU L){
    return p->next;
    /* Devolvemos la posición siguiente de la indicada.*/
}

tPosU previousU(tPosU p, tListU L){
    tPosU q;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    if (p == L){
        return NULLU;
        /* Si la posición indicada es la primera no hay previo, devolvemos nulo.*/
    }else{
        /* En caso contrario debemos recorrer la lista hasta esa posición.*/
        for (q = L; q->next != p; q = q->next);
        return q;
        /* El bucle lo recorremos hasta justo la posición anterior a la que se indica (q->next != p) y así ya tenemos
        * directamente el valor previo.*/
    }
}

tPosU findPosition(tListU L, tItemU Item){
    tPosU p;
    p = L;
    while(p->next!= NULLU && (strcmp(p->next->data.userName, Item.userName) < 0)){
        p = p->next;
    }
    return p;
}

bool insertItemU(tItemU Item, tListU *L) {
    tPosU p, q;
    if(!createNodeU(&p)){
        return false;
    }else{
        p->data = Item;
        p->next = NULLU;
        if(isEmptyListU(*L)){
            *L = p;
        }else if(strcmp(Item.userName,(*L)->data.userName) < 0){
                p->next = *L;
                *L = p;
        }else{
            q = findPosition(*L, Item);
            p->next = q->next;
            q->next = p;
        }
        return true;
    }
}

void deleteAtPositionU(tPosU p, tListU *L){
    tPosU q;
        if(p == *L){
            *L = (*L)->next;
        }else if(p->next == NULLU){
            for(q = *L; q->next != p; q = q->next);
            q->next = NULLU;
        }else{
            q = p->next;
            p->data = q->data;
            p->next = q->next;
            p = q;
        }
        free(p);
}

tItemU getItemU(tPosU p, tListU L){
    return p->data;
    /* Devolvemos la data de la posición indicada.*/
}

void updateItemU(tItemU d, tPosU p, tListU *L){
    p->data = d;
    /* Actualizamos el valor en p->data.*/
}

tPosU findItemU(tUserName name, tListU L){
    tPosU p;
    /* Creamos una variable auxilar que nos ayudará con el bucle.*/
    for(p = L; (p != NULLU) && (strcmp(p->data.userName, name) != 0); p = p->next);
    /* Recorremos la lista comparando el nombre introducido con los de la lista hasta encontrar la posición en la que
     * está.*/
    if (p == NULLU || strcmp(p->data.userName,name) != 0){
        return NULLU;
        /* Si hemos llegado al final sin encontrar el name devolvemos un nulo, no ha sido posible encontrar la
         * posición o no está ese valor en la lista.*/
    }
    return p;
    /* Si lo hemos encontrado devolvemos la posición en la que está.*/
}






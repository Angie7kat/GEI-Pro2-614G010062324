/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 18 / 03 / 24
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
        /* En caso de poder crear el nodo, le asignamos el valor del item dado y le asignamos next como nulo.*/
        if (*L == LNULL) {
            *L = q;
            /* Si la lista esta vacía, le asignamos a la lista el valor del nodo creado anteriormente..*/
        } else if (p == LNULL) {
            for (r = *L; r->next != LNULL; r = r->next);
            r->next = q;
            /* En caso de que la posición sea la última de la lista, creamos un bucle para encontrar el último nodo de
             * lista y asignarle a su next el nodo creado anteriormente..*/
        } else if (p == *L) {
            q->next = p;
            *L = q;
            /* En caso de que la posición sea la primera de la lista, le asignamos al next el nodo de la primera
             * posición y lo colocamos en la primera posición de la lista.*/
        } else {
            q->data = p->data;
            p->data = d;
            q->next = p->next;
            p->next = q;
            /* Por último, Si la posición no es ni la primera ni la última, copiamos los datos del nodo p al nodo q y
             * al nodo p le asignamos los nuevos valores.*/
        }
        return true;
        /* Devolvemos verdadero tras insertar el nodo correctamente*/
    }
}

void deleteAtPosition(tPosL p, tList * L){
    tPosL q;
    /* Creamos una variable auxiliar*/
    if(p == *L){
        *L = p -> next;
        /* Si la posición dada es la primera de la lista, le asignamos al siguiente nodo la primera posición para
         * poder eliminarlo.*/
    }else if(p->next == LNULL){
        for(q = *L; q ->next != p; q = q ->next);
        q->next = LNULL;
        /* En caso de que la posición sea la última, creamos un bucle desde el principio hasta encontrar la
         * posición anterior a la posición dada.
         * Una vez encontrada le asignamos a next el valor nulo para eliminar el nodo de la última
         * posición.*/
    }else{
        q = p-> next;
        p->data = q->data;
        p->next = q->next;
        p = q;
        /* En caso de que no sea ni la primera posición ni la última, le asignamos al nodo auxiliar p el valor del
         * siguiente nodo del que queramos eliminar.
         * Reemplazamos el valor data y next de p por los valores de q para eliminar los valores anteriores y duplicar
         * el nodo q.
         * Finalmente igualamos el nodo p a q para asignarle la misma dirección y eliminar los dos.*/
    }
    free(p);
    /* Después de eliminar el nodo, eliminamos el uso de memoria.*/
}

tItemL getItem(tPosL p, tList L){
    return p->data;
    /* Devolvemos la data de la posición indicada.*/
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

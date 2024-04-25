/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 25 / 04 / 2024
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

/* Función auxiliar para facilitarnos encontrar la posición en la función de insertar un Item.*/
tPosU findPositionU(tListU L, tItemU Item){
    tPosU p;
    /* Utilizamos la variable auxiliar p para recorrer el bucle.*/
    p = L;
    /* Mientras no nos encontremos en la última posición y el valor de la siguiente posición sea menor que el Item que
     * queremos insertar en insertItemU, avanzamos en la lista hasta encontrar la posición en las que alguna de estas
     * condiciones no se cumplan.*/
    while(p->next!= NULLU && (strcmp(p->next->data.userName, Item.userName) < 0)){
        p = p->next;
    }
    /* Devolvemos la posición donde no se cumplen estas posiciones y la usaremos en la función insertItemU.*/
    return p;
}

bool insertItemU(tItemU Item, tListU *L) {
    /* Creamos las variables auxiliares p y q; p será el nodo a insertar y q nos ayudará a insertar el nodo cuando
     * haya que insertar p en cualquier otra posición que no sea la primera.*/
    tPosU p, q;
    /* Comprobamos si el nodo con el nuevo item se crea correctamente. */
    if(!createNodeU(&p)){
        /* Devolvemos falso si no se crea bien.*/
        return false;
        /* Comenzamos a mirar los casos para ver donde debemos insertar el nuevo nodo.*/
    }else{
        /* Asignamos los valores de Item al nodo creado.*/
        p->data = Item;
        p->next = NULLU;
        /* Si la lista está vacía, metemos el nodo en la primera posición.*/
        if(isEmptyListU(*L)){
            *L = p;
            /* Si el valor a insertar es menor (alfabéticamente) al que está en la primera posición de la lista,
             * tenemos que...*/
        }else if(strcmp(Item.userName,(*L)->data.userName) < 0){
            /* ... unir el nodo con la primera posición de la lista */
                p->next = *L;
                /*  y que ahora el nodo insertado pase a ser el primero de la lista.*/
                *L = p;
                /*Si no es menor entonces...*/
        }else{
            /* Obtenemos la posición en la que tenemos que insertar el item con la función auxiliar.*/
            q = findPositionU(*L, Item);
            /* Hacemos que el next del nodo a insertar sea igual al next del nodo que está en esa posición
             * actualmente.*/
            p->next = q->next;
            /* Y ahora cambiamos el next de q para que así apunte a p y ahora en la lista quedan q y luego p en ese
             * orden.*/
            q->next = p;
        }
        /* Devolvemos true si ha sido insertado correctamente.*/
        return true;
    }
}

void deleteAtPositionU(tPosU p, tListU *L){
    /* Creamos una variable auxiliar que nos ayudará a recorrer la lista.*/
    tPosU q;
    /* Si la posición a eliminar es la primera...*/
        if(p == *L){
            /* ...*L ahora es su posición siguiente por lo que eliminamos la primera.*/
            *L = (*L)->next;
            /* Si la posición a eliminar es la última...*/
        }else if(p->next == NULLU){
            /* Usamos la variable auxiliar q para recorrer la lista hasta el penúltimo elemento.*/
            for(q = *L; q->next != p; q = q->next);
            /* Al penúltimo elemento le asignamos el next a NULLU entonces se desvincula de la última posición(p) de la
             * que haremos un free más adelante para eliminarla.*/
            q->next = NULLU;
            /* Si no es ninguno de los otros casos y es una posición intermedia:*/
        }else{
            /* Utilizamos la variable auxiliar para igualarla al nodo siguiente de p(posición a eliminar)*/
            q = p->next;
            p->data = q->data;
            p->next = q->next;
            p = q;
            /* Reemplazamos el valor data y next de p por los valores de q para eliminar los valores anteriores y
             * duplicar el nodo q. Finalmente igualamos el nodo p a q para asignarle la misma dirección y eliminar
             * los dos.*/
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






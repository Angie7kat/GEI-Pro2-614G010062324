/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */

#include "song_list.h"
#include <string.h>

void createEmptyListS(tListS* L){
    L->lastPos = NULLS;
    /* Asignamos un valor nulo a la última posición para crear una lista vacía.*/
}

bool isEmptyListS(tListS L){
    return L.lastPos == NULLS;
    /* Según el valor de la última posición de la lista, devuelve verdadero si es un valor nulo(la lista está vacía),
     * y falso si tiene un valor no nulo.*/
}

tPosS firstS(tListS L){
    return 0;
    /* Devolvemos la primera posición de la lista.*/
}

tPosS lastS(tListS L){
    return L.lastPos;
    /* Devolvemos el número de la última posición de la lista.*/
}

tPosS nextS(tPosS p, tListS L){
    if(p==L.lastPos){
        return NULLS;
        /* Creamos un condicional que determina si la posición dada es la última de la lista; si es así devuelve un
         * valor nulo...*/
    }else{
        return ++p;
        /* ... En caso de que no sea la última posición de la lista, se aumenta 1 la posición para acceder al siguiente
         * elemento.*/
    }
}

tPosS previousS(tPosS p, tListS L){
    if(p==0){
        return NULLS;
        /* Creamos un condicional que determina si la posición dada es la primera de la lista. Si es asi devuelve un
         * valor nulo*/
    }else{
        return --p;
        /* A diferencia de la función next, debemos devolver el anterior por lo que se disminuye en 1 la posición de la
         * lista para acceder a la anterior.*/
    }
}
bool insertItemS(tItemS Item, tPosS p, tListS* L){
    tPosS q;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    if(L->lastPos == MAX - 1){
        return false;
        /* Creamos un condicional para comprobar si el valor puede insertarse en la posición indicada.
        *En caso de que la lista este llena, devuelve falso.*/
    }else{
        L->lastPos++;
        /* Si la lista no esta llena, aumentamos en 1 el valor de la última posición.*/
        if(p == NULLS){
            L->Item[L->lastPos] = Item;
            /* Creamos otro condicional en el que si la posición introducida es null insertamos el Item en la última
             * posición de la lista.*/
        }else{
            for(q = L->lastPos; q>p; q--){
                /* En caso de no ser null la posición introducida, creamos un bucle para recorrer la lista buscando la
                 * posición indicada.*/
                L->Item[q] = L->Item[q-1];
                /* En la última posición(que está vacía) duplicamos la información de la anterior y así hasta llegar a
                 * la posición en la que queremos insertar el Item.*/
            }
            L->Item[q] = Item;
            /* Insertamos el Item en esa posición y no quedará ningún elemento duplicado. La lista queda modificada con
             * una posición más y el item insertado en la posición deseada.*/
        }
        return true;
        /* Retornamos true si el Item ha sido insertado con éxito.*/
    }
}
void deleteAtPositionS(tPosS p, tListS* L){
    tPosS q;
    /* Creamos una variable auxiliar para recorrer un bucle.*/
    for(q=p; q<L->lastPos; q++){
        L->Item[q] = L->Item[q+1];
        /* En el bucle para borrar el Item de esa posición, nos posicionamos en ella y copiamos el elemento de la
         * siguiente posición en este para así eliminarlo.
         * Ahora tenemos en mismo Item en dos posiciones y para eso el bucle va haciendo lo mismo con el resto de
         * posiciones; así el elemento queda eliminado y la última posición y la anterior con el mismo elemento, por
         * lo que ... */
    }
    L->lastPos--;
    /* ... Lo siguiente que hacemos es eliminar la última posición y así obtenemos la lista sin el elemento de
     * la posición deseada y sin ningún elemento duplicado. */
}

tItemS getItemS(tPosS p, tListS L){
    return L.Item[p];
    /* Devolvemos el contenido que hay en la posición dada.*/
}

void updateItemS(tItemS Item, tPosS p, tListS* L){
    L->Item[p] = Item;
    /* Cambiamos el contenido de la posición por el valor indicado.*/
}

tPosS findItemS(tSongTitle title, tListS L){
    tPosS p;
    /* Creamos una variable auxiliar para recorrer un bucle.*/
    if(L.lastPos == NULLS){
        return NULLS;
        /* Creamos un condicional que devuelve nulo si la lista está vacía. */
    }else{
        for (p = 0; p <= L.lastPos; ++p){
            /* En caso de que no esté vacía, creamos un bucle desde 0 hasta la última posición de la lista.*/
            if (strcmp(title, L.Item[p].songTitle) == 0) {
                return p;
                /* Finalmente creamos un condicional que busca el nombre del user asegurándose de que el contenido
                 * de la posición del bucle sea igual al nombre dado y al encontrarlo devolvemos esta posición.*/
            }
        }
        return NULLS;
        /* Si no lo encuentra devuelve nulo.*/
    }
}

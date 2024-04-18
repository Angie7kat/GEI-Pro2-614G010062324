/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 18 / 04 / 2024
 */

#ifndef USER_LIST_H
#define USER_LIST_H

#include "types.h"
#include "song_list.h"
#include <stdbool.h>
#define NULLU NULL

typedef struct tNode* tPosU;
typedef struct{
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
}tItemU;
struct tNode{
    tItemU data;
    tPosU next;
};

typedef tPosU tListU;

void createEmptyListU(tListU* L);
/*
 * Objetivo: Crea una lista vacía.
 * Entradas: El nombre de la lista a crear.
 * Salidas: Esta nueva lista vacía.
 * PreCD: Ninguna.
 * PostCD: La lista queda creada, inicializada y está vacía.
 */
bool isEmptyListU(tListU L);
/*
 * Objetivo: Determinar si una lista está vacía.
 * Entradas: La lista a inspeccionar.
 * Salidas: Devuelve true si la lista está vacía y false si no lo está.
 * PreCD: Que la lista exista.
 * PostCD: Ninguna.
 */
tPosU firstU(tListU L);
/*
 * Objetivo: Devuelve la posición del primer elemento de la lista.
 * Entradas: La lista sobre la que se quiere obtener la primera posición.
 * Salidas: La primera posición de la lista.
 * PreCD: La lista no puede estar vacía.
 * PostCD: Ninguna.
 */
tPosU lastU(tListU L);
/*
 * Objetivo: Devolver la posición del último elemento de la lista.
 * Entradas: La lista de la que se quiere obtener el último elemento.
 * Salidas: La posición del último elemento de la lista.
 * PreCD: La lista no puede estar vacía.
 * PostCD: Ninguna.
 */
tPosU nextU(tPosU p, tListU L);
/*
 * Objetivo: Devolver en la lista indicada el elemento siguiente al de la posición indicada(o NULLU si la posición no tiene siguiente).
 * Entradas: Una lista y la posición de la que se quiere obtener el siguiente.
 * Salidas: La posición del siguiente elemento de la lista (o NULLU si la posición no tiene siguiente).
 * PreCD: La posición introducida tiene que ser válida dentro de la lista.
 * PostCD: Ninguna.
 */
tPosU previousU(tPosU p, tListU L);
/*
 * Objetivo: Devolver la posición en la lista del elemento anterior al de la posición indicada(o NULLU si la posición no tiene anterior).
 * Entradas: Una lista y la posición de la que se quiere obtener el anterior.
 * Salidas: La posición anterior a la dada (o NULLU si la posición no tiene anterior).
 * PreCD: La posición introducida tiene que ser válida dentro de la lista.
 * PostCD: Ninguna
 */
bool insertItemU(tItemU Item, tListU* L);
/*
 * Objetivo: Insertar en la lista de forma ordenada, en función del campo username.
 * Entradas: El item a insertar y la lista en la que se quiere insertar.
 * Salidas: Devuelve un valor true si el elemento fue insertado; false en caso contrario.
 * PreCD: Que la lista esté inicializada.
 * PostCD:Las posiciones de los elementos de la lista posteriores al insertado pueden cambiar de valor.
*/
void deleteAtPositionU(tPosU p , tListU* L);
/*
 * Objetivo: Elimina de la lista el elemento que ocupa la posición indicada.
 * Entradas: La posición donde queremos eliminar y la lista donde está el elemento a borrar.
 * Salidas: La lista modificada sin el elemento de la posición indicada.
 * PreCD: La posición indicada es una posición válida en la lista y el usuario en dicha posición tiene una lista de canciones vacía.
 * PostCD: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado.
*/
tItemU getItemU(tPosU p, tListU L);
/*
 * Objetivo: Devolver el contenido del elemento de la lista que ocupa la posición indicada.
 * Entradas: La posición de la lista que se quiere consultar y la lista en la que se encuentra.
 * Salidas: La información del elemento en esa posición de la lista.
 * PreCD: La posición indicada es una posición válida en la lista.
 * PostCD: Ninguna.
 */
void updateItemU(tItemU d, tPosU p, tListU* L);
/*
 * Objetivo: Modificar el contenido del elemento situado en la posición dada.
 * Entradas: El contenido que se quiere modificar, la posición que va a ser actualizada y la lista en la que se encuentra.
 * Salidas: Lista modificada con el elemento actualizado.
 * PreCD: La posición indicada es una posición válida en la lista.
 * PostCD: El orden de los elementos de la lista no se ve modificado.
 */
tPosU findItemU(tUserName name, tListU L);
/*
 * Objetivo: Devolver la posición del primer elemento de la lista cuyo nombre de usuario se corresponda con el indicado.
 * Entradas: Nombre del usuario y la lista en la que se va a buscar.
 * Salidas: Devolver la posición del elemento buscado.
 * PreCD: Ninguna.
 * PostCD: Ninguna.
 */

#endif

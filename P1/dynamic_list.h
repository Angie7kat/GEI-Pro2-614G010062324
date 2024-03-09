/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 09 / 03 / 24
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <stdbool.h>
#define LNULL NULL

#include "types.h"

typedef struct tNode* tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

void createEmptyList(tList* L);
/*
 * Objetivo: Crea una lista vacía.
 * Entradas: El nombre de la lista a crear.
 * Salidas: Esta nueva lista vacía.
 * PreCD: Ninguna.
 * PostCD: La lista queda creada, inicializada y está vacía.
 */
bool isEmptyList(tList L);
/*
 * Objetivo: Determinar si una lista está vacía.
 * Entradas: La lista a inspeccionar.
 * Salidas: Devuelve true si la lista está vacía y false si no lo está.
 * PreCD: Que la lista exista.
 * PostCD: Ninguna.
 */
tPosL first(tList L);
/*
 * Objetivo: Devuelve la posición del primer elemento de la lista.
 * Entradas: La lista sobre la que se quiere obtener la primera posición.
 * Salidas: La primera posición de la lista.
 * PreCD: La lista no puede estar vacía.
 * PostCD: Ninguna.
 */
tPosL last(tList L);
/*
 * Objetivo: Devolver la posición del último elemento de la lista.
 * Entradas: La lista de la que se quiere obtener el último elemento.
 * Salidas: La posición del último elemento de la lista.
 * PreCD: La lista no puede estar vacía.
 * PostCD: Ninguna.
 */
tPosL next(tPosL p, tList L);
/*
 * Objetivo: Devolver en la lista indicada el elemento siguiente al de la posición indicada(o LNULL si la posición no tiene siguiente).
 * Entradas: Una lista y la posición de la que se quiere obtener el siguiente.
 * Salidas: La posición del siguiente elemento de la lista (o LNULL si la posición no tiene siguiente).
 * PreCD: La posición introducida tiene que ser válida dentro de la lista.
 * PostCD: Ninguna.
 */
tPosL previous(tPosL p, tList L);
/*
 * Objetivo: Devolver la posición en la lista del elemento anterior al de la posición indicada(o LNULL si la posición no tiene anterior).
 * Entradas: Una lista y la posición de la que se quiere obtener el anterior.
 * Salidas: La posición anterior a la dada (o LNULL si la posición no tiene anterior).
 * PreCD: La posición introducida tiene que ser válida dentro de la lista.
 * PostCD: Ninguna
 */
bool insertItem(tItemL d, tPosL p, tList* L);
/*
 * Objetivo: Inserta un elemento en la lista en la posición indicada. Si la posición es LNULL, entonces se añade al final.
 * Entradas: El elemento a insertar, su posición y la lista en la que se va a introducir.
 * Salidas: Devuelve un valor true si el elemento fue insertado y la lista modificada con el nuevo item añadido; false en caso contrario.
 * PreCD: La posición indicada es una posición válida en la lista o bien nula (LNULL).
 * PostCD: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado.
 */
void deleteAtPosition(tPosL p, tList * L);
/*
 * Objetivo: Elimina de la lista el elemento que ocupa la posición indicada.
 * Entradas: La posición donde está el elemento que se quiere eliminar y la lista en la que se encuentra.
 * Salidas: La lista modificada sin el elemento de la posición indicada.
 * PreCD: La posición indicada es una posición válida en la lista.
 * PostCD: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado.
 */
tItemL getItem(tPosL p, tList L);
/*
 * Objetivo: Devolver el contenido del elemento de la lista que ocupa la posición indicada.
 * Entradas: La posición de la lista que se quiere consultar y la lista en la que se encuentra.
 * Salidas: La información del elemento en esa posición de la lista.
 * PreCD: La posición indicada es una posición válida en la lista.
 * PostCD: Ninguna.
 */
void updateItem(tItemL d, tPosL p, tList * L);
/*
 * Objetivo: Modificar el contenido del elemento situado en la posición dada.
 * Entradas: El contenido que se quiere modificar, la posición que va a ser actualizada y la lista en la que se encuentra.
 * Salidas: Lista modificada con el elemento actualizado.
 * PreCD: La posición indicada es una posición válida en la lista.
 * PostCD: El orden de los elementos de la lista no se ve modificado.
 */
tPosL findItem(tUserName name, tList L);
/*
 * Objetivo: Devolver la posición del primer elemento de la lista cuyo nombre de usuario se corresponda con el indicado.
 * Entradas: Nombre del usuario y la lista en la que se va a buscar.
 * Salidas: Devolver la posición del elemento buscado.
 * PreCD: Ninguna.
 * PostCD: Ninguna.
 */

#endif

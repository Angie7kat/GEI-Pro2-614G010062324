/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

/* Función auxiliar que nos ayudará a imprimir los valores de tUserCategory ya que este es un enum.*/
char *changeTypeToChar(tUserCategory category){
    if(category == 0){
        return "basic";
        /* En caso de que el enum valga 0, devuelve basic en tipo char.*/
    }else{
        return "pro";
        /* De lo contrario, devuelve pro en tipo char.*/
    }
}

/* Función auxiliar que nos ayudará a introducir un valor char y pasarlo a enum para asignarlo a tUserCategory.*/
tUserCategory changeTypeToEnum(char * category){
    if(strcmp(category,"basic") == 0){
        return basic;
        /* En caso de que su valor sea basic, devuelve basic en tipo enum.*/
    }else{
        return pro;
        /* De lo contrario, devuelve pro en tipo enum.*/
    }
}

/*    NEW
 * Objetivo: Dar de alta a un usuario basic o pro.
 * Entradas: La lista de usuarios, el nombre del nuevo usuario, la categoría que tendrá este usuario.
 * Salidas: La lista con ahora un usuario nuevo.
 * PreCD: La lista de usuarios debe estar inicializada.
 * PostCD: Las posiciones de los usuarios pueden haber variado.
 */
void new(tListU *L, tUserName name, tUserCategory category){
    tItemU item1;

    tPosU pos;
    pos = findItemU(name, *L);

    if(pos == NULLU){
        strcpy(item1.userName, name);
        item1.totalPlayTime = 0;
        item1.userCategory = category;
        createEmptyListS(&item1.songList);
        insertItemU(item1, L);
        printf("* New: user %s category %d\n", name, category);
    }else{
        printf("+ Error: New not possible\n");
    }
}
/*    DELETE
 * Objetivo: Eliminar un usuario.
 * Entradas: La lista de usuarios y el usuario a eliminar.
 * Salidas: La lista con el usuario eliminado.
 * PreCD: La lista de usuarios debe estar inicializada.
 * PostCD: Las posiciones de los usuarios pueden haber variado.
 */
// función delete

/*    ADD
 * Objetivo: Añadir una nueva canción a la lista de reproducción.
 * Entradas: La lista de usuarios, el usuario que quiere insertar una nueva canción y el título de esta.
 * Salidas: La lista en de canciones ha aumentado en un usuario si esta canción no estaba ya en la lista.
 * PreCD: La lista de usuarios y de canciones debe estar inicializada.
 * PostCD: Las posiciones de las canciones pueden haber variado.
 */
void add(tListU *L, tUserName name, tSongTitle song) {
    if(isEmptyListU(*L))
        printf("+ Error: Add not possible");
    else if(findItemU(name, *L) != NULLU)
        printf("+ Error: Add not possible");
    else {
        tItemU usuario = getItemU(findItemU(name, *L), *L);
        if(isEmptyListS(usuario.songList))
            printf("+ Error: Add not possible");
        else if(findItemS(song, usuario.songList) != NULLS)
            printf("+ Error: Add not possible");
        else{
            tItemS item;
            strcpy(item.songTitle, song);
            item.playTime = 0;
            if(!insertItemS(item, NULLS, &usuario.songList))
                printf("+ Error: Add not possible");
            else
                printf("* Add: user %s adds song %s", name, song);

        }
    }
}
/*    UPGRADE
 * Objetivo: Actualizar la categoría de un usuario de basic a pro.
 * Entradas: La lista de usuarios y el nombre del usuario.
 * Salidas: La lista modificada con la categoría del usuario actualizada.
 * PreCD: La lista debe de estar inicializada.
 */
// función upgrade

/*    PLAY
 * Objetivo:
 * Entradas:
 * Salidas:
 * PreCD:
 * PostCD:
 */
// función play

/*    STATS
 * Objetivo: Imprimir toda la lista de usuarios de MUSFIC y sus datos.
 * Entradas: La lista a imprimir.
 * Salidas: Impresión de la lista.
 * PreCD: La lista debe estar inicializada.
 */
void stats(tListU L){
    tPosU i;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    if(isEmptyListU(L)) {
        printf("+ Error: Stats not possible\n");
        /* Si la lista está vacía, muestra error.*/
    }
    else {
        int cntCategory0 = 0, cntCategory1 = 0, cntPlays0 = 0, cntPlays1 = 0;
        /* Si no está vacía, creamos variables para contar los diferentes categorías.*/
        i = firstU(L);
        while (i != NULLU) {
            /* Creamos un bucle desde la primera posición de la lista hasta la última.*/
            tItemU Usuario = getItemU(i, L);
            /* Recopilamos los datos del usuario asignado a cada posición.*/
            if(Usuario.userCategory == 0) {
                cntCategory0++;
                cntPlays0 += Usuario.totalPlayTime;
                /* En caso de ser de la categoría basic, añadimos 1 al contador basic y sumamos las reproducciones de
                 * su categoría.*/
            }
            else {
                cntCategory1++;
                cntPlays1 += Usuario.totalPlayTime;
                /* Si pertenece a la categoría pro, añadimos 1 al contador pro y sumamos las reproducciones de su
                 * categoría.*/
            }
            printf("User %s category %s totalplaytime %d\n",Usuario.userName, changeTypeToChar(Usuario.userCategory), Usuario.totalPlayTime);
            /* Imprimimos por pantalla los datos de cada usuario.*/
            i = nextU(i, L);
        }
    }
}
/*    REMOVE
 * Objetivo: Eliminar todos los usuarios basic cuyo contador de tiempo de reproducción exceda maxTime minutos.
 * Entradas: La lista de usuarios y maxTime.
 * Salidas: La lista sin los usuarios que excedían el maxTime.
 * PreCD: La lista de usuarios está inicializada.
 * PostCD: La lista de usuarios puede haber variado.
 */

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListU *L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            new(L,param1, changeTypeToEnum(param2));
            break;
        case 'D':
            printf("********************\n");
            break;
        case 'A':
            printf("********************\n");
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            add(L,param1,param2);
            break;
        case 'U':
            printf("********************\n");
            break;
        case 'P':
            printf("********************\n");
            break;
        case 'S':
            printf("********************\n");
            break;
        case 'R':
            printf("********************\n");
            break;
        default:
            break;
    }
}

void readTasks(char *filename, tListU *L) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}



int main(int nargs, char **args) {
    tListU L;
    char *file_name = "new.txt";
    createEmptyListU(&L);
    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &L);

    return 0;
}
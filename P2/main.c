/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 18 / 04 / 2024
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

/* Función auxiliar que nos ayudará a calcular el promedio en la función stats ya que los valores a dividir son int
 * y queremos que sea float.*/
float average (int category, int plays){
    if(category == 0 || plays == 0)
        return 0;
        /* Si los valores ingresados son 0, devuelve el valor 0.*/
    else{
        return ((float)plays / (float)category);
        /* De lo contrario devuelve el promedio.*/
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
    tPosU pos;
    pos = findItemU(name, *L);
    /* Creamos una variable auxiliar tPosU para comprobar si el usuario ya está en la lista.*/
    if(pos == NULLU){
        /* Si no está en la lista entonces...*/
        tItemU usuario;
        strcpy(usuario.userName, name);
        usuario.totalPlayTime = 0;
        usuario.userCategory = category;
        createEmptyListS(&usuario.songList);
        /* ... Creamos un tItemU usuario al que le asignaremos toda la información introducida.*/
        if(insertItemU(usuario, L)) {
            /* Si es insertado en la lista correctamente...*/
            printf("* New: user %s category %s\n", name, changeTypeToChar(category));
            /* ... Mostramos en pantalla sus datos.*/
        }else{
            /* Si no ha sido insertado correctamente devolvemos error.*/
            printf("+ Error: New not possible\n");
        }
    }else{
        printf("+ Error: New not possible\n");
        /* Si el usuario ya está en la lista devuelve error.*/
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
void add(tListU *L, tUserName name, tSongTitle song){
    /* Si la lista no tiene ningún usuario no podemos añadir la canción a ningún usuario.*/
    if(isEmptyListU(*L)){
        printf("+ Error: Add not possible\n");
    }else if(findItemU(name, *L) == NULLU){
        /* Si no encuentra el usuario donde se quiere aumentar la lista de canciones devuelve error.*/
        printf("+ Error: Add not possible\n");
    }else{
        tItemU usuario = getItemU(findItemU(name, *L), *L);
        /* Una vez pasados los filtros usaremos un tItemU para obtener todos los datos del usuario que quiere introducir
         * la canción y miraremos si la canción ya está añadida o no.*/
        if(findItemS(song, usuario.songList) != NULLS){
            /* Si la canción ya está en la lista de canciones mostramos un error.*/
            printf("+ Error: Add not possible\n");
        }else{
            tItemS cancion;
            strcpy(cancion.songTitle, song);
            cancion.playTime = 0;
            /* Si la canción no está en la lista de canciones debemos insertarla entonces usamos un tItemS para
             * introducir los datos de la canción en la lista.*/
            if(!insertItemS(cancion, NULLS, &usuario.songList)){
                /* Si no es capaz de insertarla devolvemos un error.*/
                printf("+ Error: Add not possible\n");
            }else{
                updateItemU(usuario,findItemU(name, *L),L);
                /* Si ha sido insertada correctamente actualizamos el usuario, ya que hemos insertado una nueva canción
                 * en la lista de canciones de un usuario y mostraremos por pantalla el usuario y la canción añadida.*/
                printf("* Add: user %s adds song %s\n", name, song);
            }
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
    tPosS u;
    /* Creamos dos variables auxiliares para recorrer los bucles.*/
    if(isEmptyListU(L)){
        printf("+ Error: Stats not possible\n");
        /* Si la lista de usuarios está vacía, muestra error, no hay nada que imprimir.*/
    }else{
        int cntCategory0 = 0, cntCategory1 = 0, cntTotalPlay0 = 0, cntTotalPlay1 = 0;
        /* Si no está vacía, creamos variables para contar los diferentes categorías.*/
        i = firstU(L);
        while (i != NULLU){
            /* Creamos un bucle desde la primera posición de la lista hasta la última.*/
            tItemU usuario = getItemU(i, L);
            /* Recopilamos los datos del usuario asignado a cada posición.*/
            if(usuario.userCategory == 0){
                cntCategory0++;
                cntTotalPlay0 += usuario.totalPlayTime;
                /* En caso de ser de la categoría basic, añadimos 1 al contador basic y sumamos el totalPlayTime de
                 * su categoría.*/
            }else{
                cntCategory1++;
                cntTotalPlay1 += usuario.totalPlayTime;
                /* Si pertenece a la categoría pro, añadimos 1 al contador pro y sumamos el totalPlayTime de su
                 * categoría.*/
            }
            printf("User %s category %s totalplaytime %d\n", usuario.userName, changeTypeToChar(usuario.userCategory), usuario.totalPlayTime);
            /* Mostramos la información del usuario por pantalla y ahora nos disponemos a imprimir sus canciones:*/
            if(isEmptyListS(usuario.songList)){
                /* Si la lista de canciones está vacía no hay, imprimimos No songs.*/
                printf("No songs\n");
            }else{
                /* Si sí hay canciones, una o varias, debemos recorrer la lista de canciones e ir imprimiendo la
                 * información de cada una.*/
                for(u = firstS(usuario.songList); u != NULLS; u = nextS(u, usuario.songList)){
                    printf("Song %s playtime %d\n", getItemS(u, usuario.songList).songTitle, usuario.totalPlayTime);
                }
            }
            printf("\n");
            i = nextU(i, L);
        }
        printf("Category  Users  TimePlay  Average\n");
        printf("Basic     %5d %9d %8.2f\n", cntCategory0, cntTotalPlay0, average(cntCategory0, cntTotalPlay0));
        printf("Pro       %5d %9d %8.2f\n", cntCategory1, cntTotalPlay1, average(cntCategory1, cntTotalPlay1));
        /* Finalmente creamos una tabla para mostrar la información de cada categoría con el número de usuarios,
         * tiempo total de reproducción y el promedio.*/
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
            printf("%s %c:\n", commandNumber, command);
            stats(*L);
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
/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 25 / 04 / 2024
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
float average(int category, int plays){
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
    /* Creamos una variable auxiliar tPosU para buscar si el usuario ya está en la lista.*/
    if(pos == NULLU){
        /* Si no está en la lista entonces...*/
        tItemU usuario;
        strcpy(usuario.userName, name);
        usuario.totalPlayTime = 0;
        usuario.userCategory = category;
        createEmptyListS(&usuario.songList);
        /* ... Creamos un tItemU usuario al que le asignaremos toda la información introducida.*/
        if(insertItemU(usuario, L)){
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
void delete(tListU *L, tUserName name) {
    tPosU pos;
    pos = findItemU(name, *L);
    /* Creamos una variable auxiliar para buscar el usuario que queremos eliminar.*/
    if(isEmptyListU(*L)){
        /* Si la lista está vacía no hay ningún usuario que borrar entonces devolvemos un error.*/
        printf("+ Error: Delete not possible\n");
    }else if(pos == NULLU){
        /* Si el usuario a eliminar no está en la lista o findItem no lo encuentra devolvemos error.*/
        printf("+ Error: Delete not possible\n");
    }else{
        /* Si sí está en la lista, comenzamos con el proceso de eliminación.*/
        tItemU usuario;
        usuario = getItemU(pos, *L);
        /* Utilizamos un tItemU usuario para almacenar la información del usuario a eliminar.
         * Según las precondiciones de deleteAtPositionU para borrar un usuario esta función debe recibir usuario con
         * la lista de canciones vacía por lo que procedemos a hacer las comprobaciones necesarias.*/
        if(isEmptyListS(usuario.songList)){
            /* Si la lista de canciones ya está vacía podemos utilizar deleteAtPositionU sin problema y eliminar el
             * usuario.*/
            deleteAtPositionU(pos, L);
            printf("* Delete: user %s category %s totalplaytime %d\n", name, changeTypeToChar(usuario.userCategory),usuario.totalPlayTime);
            /* Imprimimos los datos del usuario eliminado.*/
        }else{
            /* Si la lista de canciones no está vacía debemos vaciarla.*/
            tPosS u,aux;
            /* Hacemos un bucle que desde la última canción hasta la primera va vaciando la lista de canciones.*/
            u = lastS(usuario.songList);
            while(u != NULLS){
                aux = previousS(u,usuario.songList);
                deleteAtPositionS(u,&usuario.songList);
                u = aux;
            }
            updateItemU(usuario,pos, L);
            /* Actualizamos y comprobamos si se ha vaciado bien la lista de canciones.*/
            if(isEmptyListS(usuario.songList)){
                /* Si se ha vaciado correctamente borramos el usuario e imprimimos su información.*/
                deleteAtPositionU(pos, L);
                printf("* Delete: user %s category %s totalplaytime %d\n", name, changeTypeToChar(usuario.userCategory),usuario.totalPlayTime);
            }else{
                /* Si la lista de canciones no se ha vaciado correctamente enseñamos un error.*/
                printf("+ Error: Delete not possible\n");
            }
        }
    }
}

/*    ADD
 * Objetivo: Añadir una nueva canción a la lista de reproducción.
 * Entradas: La lista de usuarios, el usuario que quiere insertar una nueva canción y el título de esta.
 * Salidas: La lista de canciones aumentará en un usuario si esta canción no estaba ya en la lista.
 * PreCD: La lista de usuarios y de canciones debe estar inicializada.
 * PostCD: Las posiciones de las canciones pueden haber variado.
 */
void add(tListU *L, tUserName name, tSongTitle song){
    tPosU pos;
    pos = findItemU(name, *L);
    /* Creamos una variable auxiliar para encontrar el usuario sobre el que se quiere añadir la canción.*/
    if(isEmptyListU(*L)){
        /* Si la lista no tiene ningún usuario no podemos añadir la canción a ningún usuario, devolvemos un error.*/
        printf("+ Error: Add not possible\n");
    }else if(pos == NULLU){
        /* Si no encuentra el usuario donde se quiere aumentar la lista de canciones devuelve error.*/
        printf("+ Error: Add not possible\n");
    }else{
        tItemU usuario = getItemU(pos, *L);
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
                updateItemU(usuario,pos,L);
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
void upgrade(tListU *L, tUserName name){
    tPosU pos;
    pos = findItemU(name, *L);
    /* Creamos una variable auxiliar para buscar el usuario sobre el que se quiere hacer el upgrade.*/
    if(isEmptyListU(*L)){
        printf("+ Error: Upgrade not possible\n");
        /* En caso de que la lista esté vacía, devuelve error.*/
    }else if(pos == NULLU){
        printf("+ Error: Upgrade not possible\n");
        /* Si la lista no está vacía, pero el usuario no existe, también da error.*/
    }else{
        /* Si hemos pasado todos los filtros obtenemos el usuario en un tItemU.*/
        tItemU usuario = getItemU(pos,*L);
        if(strcmp(changeTypeToChar(usuario.userCategory), "pro") == 0){
            /* Si el usuario ya es de categoría pro no podemos actualizarlo entonces damos un error.*/
            printf("+ Error: Upgrade not possible\n");
        }else{
            /* Si es de categoría basic entonces actualizamos su información e imprimimos los nuevos datos con el
             * upgrade hecho.*/
            usuario.userCategory = changeTypeToEnum("pro");
            updateItemU(usuario, pos, L);
            printf("* Upgrade: user %s category %s\n", name, changeTypeToChar(usuario.userCategory));
        }
    }
}

/*    PLAY
 * Objetivo: Añadir los minutos de una canción a un usuario.
 * Entradas: La lista de usuarios, el usuario sobre el que se quiere actualizar el tiempo, el titulo de la canción y el tiempo que tiene dicha canción.
 * Salidas: La lista modificada con unos nuevos tiempos de reproducción.
 * PreCD: La lista de usuarios debe estar inicializada.
 */
void play(tListU *L, tUserName name, tSongTitle song, tPlayTime tiempo) {
    tPosU pos;
    pos = findItemU(name, *L);
    /* Creamos una variable auxiliar para comprobar si existe el usuario.*/
    if(isEmptyListU(*L))
        /* Si la lista de usuarios está vacía devolvemos un error.*/
        printf("+ Error: Play not possible\n");
    else if(pos == NULLU)
        /* Si no se ha encontrado el usuario en la lista también devolvemos un error.*/
        printf("+ Error: Play not possible\n");
    else{
        /* Si no se cumple ninguna de las anteriores condiciones.*/
        tItemU usuario;
        usuario = getItemU(pos, *L);
        tPosS posCancion;
        posCancion = findItemS(song, usuario.songList);
        /* Almacenamos el usuario en un tItemU usuario y buscamos la posición de la canción a la que aumentarle el
         * tiempo de reproducción en la lista de canciones de este usuario.*/
        if(posCancion == NULLS)
            /* Si no hemos encontrado la canción devolvemos un error.*/
            printf("+ Error: Play not possible\n");
        else{
            /* Si la canción si está en la lista entonces actualizamos el tiempo de reproducción de la canción pero
             * también el tiempo total de reproducción del usuario.*/
            tItemS cancion;
            cancion = getItemS(posCancion, usuario.songList);
            cancion.playTime = tiempo;
            usuario.totalPlayTime += tiempo;
            updateItemS(cancion, posCancion, &usuario.songList);
            updateItemU(usuario, pos,L);
            printf("* Play: user %s plays song %s playtime %d totalplaytime %d\n", name, song, tiempo, usuario.totalPlayTime);
        }
    }
}

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
        while(i != NULLU){
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
                    printf("Song %s playtime %d\n", getItemS(u, usuario.songList).songTitle, getItemS(u, usuario.songList).playTime);
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
 * Objetivo: Elimina todos los usuarios basic cuyo contador de tiempo de reproducción exceda maxTime minutos.
 * Entradas: La lista de usuarios y maxTime.
 * Salidas: La lista sin los usuarios que excedían el maxTime.
 * PreCD: La lista de usuarios está inicializada.
 * PostCD: La lista de usuarios puede haber variado.
 */
void removeU(tListU *L, tPlayTime maxTime){
    tPosU pos;
    tPosU pos_aux;
    /* Creamos una variable auxiliar para recorrer las listas y buscar los usuarios a eliminar y  otra auxiliar para
     * guardar la posición anterior. */
    if(isEmptyListU(*L)){
        printf("+ Error: Remove not possible\n");
        /* Si la lista de canciones está vacía devolvemos un error.*/
    }else{
        tItemU usuario;
        /* Creamos un tItemU para ir guardando cada usuario de cada posición e ir mirando si pasa las condiciones
         * necesarias para ser eliminado.*/
        pos = firstU(*L);
        while(pos != NULLU ){
            usuario = getItemU(pos,*L);
            /* Vamos obteniendo cada usuario de la lista y comprobamos si pasa los requerimientos para ser eliminado.*/
            if(strcmp(changeTypeToChar(usuario.userCategory), "basic") == 0 && usuario.totalPlayTime > maxTime){
                /* Si pasa las condiciones procedemos a eliminar el usuario y para ello primero debemos vaciar la lista
                 * de canciones del usuario.*/
                if(isEmptyListS(usuario.songList)){
                    /* Si el usuario ya tiene la lista de canciones vacías procedemos a eliminarlo directamente.*/
                    printf("Removing user %s totalplaytime %d\n", usuario.userName, usuario.totalPlayTime);
                    if(pos == *L){
                        deleteAtPositionU(pos,L);
                        pos = *L;
                        /* En caso de que la posición sea la primera de la lista, eliminamos el usuario y le
                        * asignamos a pos la primera posición de la lista. */
                    }else{
                        pos_aux = previousU(pos, *L);
                        deleteAtPositionU(pos,L);
                        pos = pos_aux;
                        /* En caso de que la posición no sea la primera, creamos una variable para almacenar la
                        * posición anterior al usuario, eliminamos el usuario e igualamos pos a la variable
                        * creada. */
                    }
                }else{
                    /* Si no está vacía la lista de canciones procedemos a vaciarla.*/
                    tPosS u, aux;
                    /* Hacemos un bucle que desde la última canción hasta la primera va vaciando la lista de canciones.*/
                    u = lastS(usuario.songList);
                    while(u != NULLS){
                        aux = previousS(u,usuario.songList);
                        deleteAtPositionS(u,&usuario.songList);
                        u = aux;
                    }
                    updateItemU(usuario, pos, L);
                    /* Actualizamos y comprobamos si se ha vaciado bien la lista de canciones.*/
                    if(isEmptyListS(usuario.songList)){
                        /* Si se ha vaciado bien eliminamos el usuario.*/
                        printf("Removing user %s totalplaytime %d\n", usuario.userName, usuario.totalPlayTime);
                        if(pos == *L){
                            deleteAtPositionU(pos,L);
                            pos = *L;
                            /* En caso de que la posición sea la primera de la lista, eliminamos el usuario y le
                             * asignamos a pos la primera posición de la lista. */
                        }else{
                            pos_aux = previousU(pos, *L);
                            deleteAtPositionU(pos,L);
                            pos = pos_aux;
                            /* En caso de que la posición no sea la primera, creamos una variable para almacenar la
                             * posición anterior al usuario, eliminamos el usuario e igualamos pos a la variable
                             * creada. */
                        }
                    }else{
                        /* Si no damos un error.*/
                        printf("+ Error: Remove not possible\n");
                    }
                }
            }else{
                pos = nextU(pos,*L);
                /* En caso de que no cumpla los requisitos, pasamos a la siguiente posición. */
            }
        }
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListU *L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            new(L,param1, changeTypeToEnum(param2));
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: user %s \n", commandNumber, command, param1);
            delete(L,param1);
            break;
        case 'A':
            printf("********************\n");
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            add(L,param1,param2);
            break;
        case 'U':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            upgrade(L,param1);
            break;
        case 'P':
            printf("********************\n");
            printf("%s %c: user %s song %s minutes %s\n", commandNumber, command, param1, param2, param3);
            play(L, param1, param2, atoi(param3));
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c:\n", commandNumber, command);
            stats(*L);
            break;
        case 'R':
            printf("********************\n");
            printf("%s %c: maxtime %s \n", commandNumber, command, param1);
            removeU(L, atoi(param1));
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

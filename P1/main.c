/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 18 / 03 / 24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

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
float average (int category, int plays) {
    if (category == 0 && plays == 0)
        return 0;
        /* Si los valores ingresados son 0, devuelve el valor 0.*/
    else {
        return ((float)plays / (float)category);
        /* De lo contrario devuelve el promedio.*/
    }
}

void new(tList *L, tUserName userName, tUserCategory userCategory){
    if(findItem(userName,*L) != LNULL){
        printf("+ Error: New not possible\n");
        /* Si el usuario ya está implementado en la lista, devuelve error.*/
    }else{
        tItemL Usuario;
        /* En caso contrario creamos un nuevo usuario.*/
        strcpy(Usuario.userName, userName);
        Usuario.numPlay = 0;
        Usuario.userCategory = userCategory;
        /* Le asignamos los valores dados y establecemos el contador de reproducciones en 0.*/
        if(insertItem(Usuario,LNULL,L)){
            printf("* New: user %s category %s\n", userName, changeTypeToChar(userCategory));
            /* Si el usuario se ha insertado correctamente en la posición, mostramos en pantalla sus datos.*/
        }else{
            printf("+ Error: New not possible\n");
            /* Si no se ha insertado correctamente, devuelve error.*/
        }
    }
}

void delete(tList *L,tUserName userName){
    if(isEmptyList(*L)){
        printf("+ Error: Delete not possible\n");
        /* Si la lista está vacía, devuelve error, no hay nada que borrar.*/
    }else if(findItem(userName, *L) == LNULL){
        printf("+ Error: Delete not possible\n");
        /* En caso de que la lista no esté vacía y el usuario no se encuentre en ella, también devuelve error.*/
    }else{
        tItemL Usuario = getItem(findItem(userName, *L), *L);
        printf("* Delete: user %s category %s numplays %d\n", userName, changeTypeToChar(Usuario.userCategory), Usuario.numPlay);
        deleteAtPosition(findItem(userName,*L),L);
        /* En caso contrario, recopilamos sus datos y su posición en la lista, los imprimimos en pantalla y lo
         * eliminamos.*/
    }
}

void upgrade(tList *L, tUserName userName){
    tItemL Usuario = getItem(findItem(userName, *L), *L);
    /* Recopilamos la información del usuario.*/
    if(isEmptyList(*L)){
        printf("+ Error: Upgrade not possible\n");
        /* En caso de que la lista esté vacía, devuelve error.*/
    }else if(findItem(userName, *L) == LNULL){
        printf("+ Error: Upgrade not possible\n");
        /* Si la lista no está vacía, pero el usuario no existe, también da error.*/
    }else if(strcmp(changeTypeToChar(Usuario.userCategory), "pro") == 0){
        printf("+ Error: Upgrade not possible\n");
        /* Si la lista no está vacía, existe el usuario y ya está en la categoría pro, devuelve error.*/
    }else{
        Usuario.userCategory = changeTypeToEnum("pro");
        updateItem(Usuario, findItem(userName,*L),L);
        printf("* Upgrade: user %s category %s\n", userName, changeTypeToChar(Usuario.userCategory));
        /* En caso de que el usuario pertenezca a la categoría basic, lo cambiamos a categoría pro e imprimimos sus
         * datos en pantalla.*/
    }
}

void play(tList *L, tUserName userName, tSongTitle songTitle){
    if(isEmptyList(*L)){
        printf("+ Error: Play not possible\n");
        /* Si la lista está vacía, devuelve error.*/
    }else if(findItem(userName, *L) == LNULL){
        printf("+ Error: Play not possible\n");
        /* En caso de que no exista el usuario, también devuelve error.*/
    }else{
        tItemL Usuario = getItem(findItem(userName, *L), *L);
        /* Si el usuario existe, recopilamos sus datos.*/
        Usuario.numPlay ++;
        /* Le añadimos 1 reproducción al contador de reproducciones.*/
        updateItem(Usuario, findItem(userName,*L),L);
        printf("* Play: user %s plays song %s numplays %d\n", userName,songTitle, Usuario.numPlay);
        /* Actualizamos sus datos y los imprimimos en pantalla.*/
    }
}

void stats(tList L){
    tPosL i;
    /* Creamos una variable auxiliar para recorrer el bucle.*/
    if(isEmptyList(L)) {
        printf("+ Error: Stats not possible\n");
        /* Si la lista está vacía, muestra error.*/
    }
    else {
        int cntCategory0 = 0, cntCategory1 = 0, cntPlays0 = 0, cntPlays1 = 0;
        /* Si no está vacía, creamos variables para contar los diferentes categorías.*/
        for (i = first(L); i != LNULL; i=next(i, L)) {
            /* Creamos un bucle desde la primera posición de la lista hasta la última.*/
            tItemL Usuario = getItem(i, L);
            /* Recopilamos los datos del usuario asignado a cada posición.*/
            if(Usuario.userCategory == 0) {
                cntCategory0++;
                cntPlays0 += Usuario.numPlay;
                /* En caso de ser de la categoría basic, añadimos 1 al contador basic y sumamos las reproducciones de
                 * su categoría.*/
            }
            else {
                cntCategory1++;
                cntPlays1 += Usuario.numPlay;
                /* Si pertenece a la categoría pro, añadimos 1 al contador pro y sumamos las reproducciones de su
                 * categoría.*/
            }
            printf("User %s category %s numplays %d\n",Usuario.userName, changeTypeToChar(Usuario.userCategory), Usuario.numPlay);
            /* Imprimimos por pantalla los datos de cada usuario.*/
        }
        printf("Category  Users  Plays  Average\n");
        printf("Basic     %5d %6d %8.2f\n", cntCategory0, cntPlays0, average(cntCategory0, cntPlays0));
        printf("Pro       %5d %6d %8.2f\n", cntCategory1, cntPlays1, average(cntCategory1, cntPlays1));
        /* Finalmente creamos una tabla para mostrar la información de cada categoría con el número de usuarios,
         * reproducciones y el promedio.*/
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            new(L, param1, changeTypeToEnum(param2));
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            delete(L,param1);
            break;
        case 'U':
            printf("********************\n");
            printf("%s %c: user %s\n", commandNumber, command, param1);
            upgrade(L,param1);
            break;
        case 'P':
            printf("********************\n");
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            play(L,param1,param2);
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c:\n", commandNumber, command);
            stats(*L);
            break;
        default:
            break;
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    tList L;
    /* Creamos la variable para la lista.*/
    char *file_name = "new.txt";
    createEmptyList(&L);
    /* Creamos una lista vacía.*/
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
/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: ** / ** / **
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

char *changeTypeToChar(tUserCategory category){
    if(category == 0){
        return "basic";
    }else{
        return "pro";
    }
}

tUserCategory changeTypeToEnum(char * category){
    if(strcmp(category,"basic") == 0){
        return basic;
    }else{
        return pro;
    }
}


void new(tList L, tUserName userName, tUserCategory userCategory){
    if(findItem(userName,L) == LNULL){
        printf("+ Error: New not possible\n");
    }else{
        tPosL p = LNULL;
        tItemL Usuario;

        strcpy(Usuario.userName, userName);
        Usuario.numPlay = 0;
        Usuario.userCategory = userCategory;

        if(insertItem(Usuario,p,&L)){
            printf("* New: user %s category %s", userName, changeTypeToChar(userCategory));
        }else{
            printf("+ Error: New not possible\n");
        }
    }
}

void delete(tList L,tUserName userName){
    if(isEmptyList(L)){
        printf("+ Error: Delete not possible\n");
    }else if(findItem(userName, L) == LNULL){
        printf("+ Error: Delete not possible\n");
    }else{
        tItemL Usuario = getItem(findItem(userName, L), L);
        deleteAtPosition(findItem(userName,L),&L);
        printf("* Delete: user %s category %s numplays %d\n", userName, changeTypeToChar(Usuario.userCategory), Usuario.numPlay);
    }
}

void upgrade(tList L, tUserName userName){
    tItemL Usuario = getItem(findItem(userName, L), L);
    if(isEmptyList(L)){
        printf("+ Error: Upgrade not possible\n");
    }else if(findItem(userName, L) == LNULL){
        printf("+ Error: Upgrade not possible\n");
    }else if(strcmp(changeTypeToChar(Usuario.userCategory), "pro") == 0){
        printf("+ Error: Upgrade not possible\n");
    }else{
        Usuario.userCategory = changeTypeToEnum("pro");
        updateItem(Usuario, findItem(userName,L),&L);
        printf("* Upgrade: user %s category %s\n", userName, changeTypeToChar(Usuario.userCategory));
    }
}

void play(tList L, tUserName userName, tSongTitle songTitle){
    if(isEmptyList(L)){
        printf("+ Error: Play not possible\n");
    }else if(findItem(userName, L) == LNULL){
        printf("+ Error: Play not possible\n");
    }else{
        tItemL Usuario = getItem(findItem(userName, L), L);
        Usuario.numPlay = Usuario.numPlay + 1;
        updateItem(Usuario, findItem(userName,L),&L);
        printf("* Play: user %s plays song %s numplays %d\n", userName,songTitle, Usuario.numPlay);
    }
}

void stats(tList L){

}

void processCommand(char *commandNumber, char command, char *param1, char *param2, tList *L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            new(*L, param1, changeTypeToEnum(param2));
            break;
        case 'D':
            printf("********************\n");
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            delete(*L,param1);
            break;
        case 'U':
            printf("********************\n");
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            upgrade(*L,param1);
            break;
        case 'P':
            printf("********************\n");
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            play(*L,param1,param2);
            break;
        case 'S':
            printf("********************\n");
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
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
    char *file_name = "new.txt";
    createEmptyList(&L);
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







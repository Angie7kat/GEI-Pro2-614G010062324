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

/*    NEW
 * Objetivo: 
 * Entradas: 
 * Salidas:
 * PreCD: 
 * PostCD:
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

/*    ADD
 * Objetivo: 
 * Entradas: 
 * Salidas:
 * PreCD: 
 * PostCD:
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

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3) {

    switch (command) {
        case 'N':
            printf("Command: %s %c %s %s\n", commandNumber, command, param1, param2);
            break;
        case 'D':
            break;
        case 'A':
            break;
        case 'U':
            break;
        case 'P':
            break;
        case 'S':
            break;
        case 'R':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

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

            processCommand(commandNumber, command[0], param1, param2, param3);
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

    readTasks(file_name);

    return 0;
}

/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Fouz Suárez LOGIN 1: angela.fouz
 * AUTHOR 2: Nolan Duteil       LOGIN 2: nolan.duteil
 * GROUP: 3.1
 * DATE: 25 / 04 / 2024
 */

#ifndef PRO2_2023_P2_TYPES_H
#define PRO2_2023_P2_TYPES_H

#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

typedef char tUserName[NAME_LENGTH_LIMIT];
typedef enum {basic, pro} tUserCategory;
typedef int tPlayTime;
typedef char tSongTitle[NAME_LENGTH_LIMIT];

typedef struct Song{
    tSongTitle songTitle;
    tPlayTime playTime;
} tSong;

#endif //PRO2_2023_P2_TYPES_H

#include <stdlib.h>
#include <stdio.h>
#include "preset.h"

void preset_menu_print()
{
    system("clear");
    printf("1. Gliger\n");
    printf("2. Gosper's gliger gun\n");
    printf("3. Pulsar\n");
    printf("4. Lightweight spaceship\n");
    printf("5. Pentadecathlon\n");
}

int preset_menu_check_input(char input[2])
{
    return !(input[1] == '\0' && (input[0] >= '1' && input[0] <= '5'));
}

void preset_menu(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    preset_menu_print();
    char chose;
    while (1) {
        char temp[2];
        scanf("%s", temp);
        if (!preset_menu_check_input(temp)) {
            chose = temp[0];
            break;
        } else {
            printf("Wrong input, please input 1-5\n");
        }
    }
    switch (chose) {
    case '1':
        gliger(field);
        break;
    case '2':
        glider_gun(field);
        break;
    case '3':
        pulsar(field);
        break;
    case '4':
        spaceship(field);
        break;
    case '5':
        pentadecathlon(field);
        break;
    }
}

void glider(char field[FIELD_HEIGHT][FIELD_WIDTH)
{
    field[9][51] = '*';
    field[10][51] = '*';
    field[11][51] = '*';
    field[11][50] = '*';
    field[10][49] = '*';
}

void glider_gun(char field[FIELD_HEIGHT][FIELD_WIDTH)
{
    field[6][2] = '*';
    field[6][3] = '*';
    field[7][2] = '*';
    field[7][3] = '*';
    field[6][12] = '*';
    field[7][12] = '*';
    field[8][12] = '*';
    field[5][13] = '*';
    field[9][13] = '*';
    field[4][14] = '*';
    field[10][14] = '*';
    field[4][15] = '*';
    field[10][15] = '*';
    field[7][16] = '*';
    field[5][17] = '*';
    field[9][17] = '*';
    field[6][18] = '*';
    field[7][18] = '*';
    field[8][18] = '*';
    field[7][19] = '*';
    field[4][22] = '*';
    field[5][22] = '*';
    field[6][22] = '*';
    field[4][23] = '*';
    field[5][23] = '*';
    field[6][23] = '*';
    field[3][24] = '*';
    field[7][24] = '*';
    field[2][26] = '*';
    field[3][26] = '*';
    field[7][26] = '*';
    field[8][26] = '*';
    field[4][36] = '*';
    field[5][36] = '*';
    field[4][37] = '*';
    field[5][37] = '*';
}

void pulsar(char field[FIELD_HEIGHT][FIELD_WIDTH)
{
    field[6][44] = '*';
    field[7][44] = '*';
    field[8][44] = '*';
    field[12][44] = '*';
    field[13][44] = '*';
    field[14][44] = '*';
    field[4][46] = '*';
    field[4][47] = '*';
    field[4][48] = '*';
    field[9][46] = '*';
    field[9][47] = '*';
    field[9][48] = '*';
    field[11][46] = '*';
    field[11][47] = '*';
    field[11][48] = '*';
    field[16][46] = '*';
    field[16][47] = '*';
    field[16][48] = '*';
    field[6][49] = '*';
    field[7][49] = '*';
    field[8][49] = '*';
    field[12][49] = '*';
    field[13][49] = '*';
    field[14][49] = '*';
    field[6][51] = '*';
    field[7][51] = '*';
    field[8][51] = '*';
    field[12][51] = '*';
    field[13][51] = '*';
    field[14][51] = '*';
    field[4][52] = '*';
    field[4][53] = '*';
    field[4][54] = '*';
    field[9][52] = '*';
    field[9][53] = '*';
    field[9][54] = '*';
    field[11][52] = '*';
    field[11][53] = '*';
    field[11][54] = '*';
    field[16][52] = '*';
    field[16][53] = '*';
    field[16][54] = '*';
    field[6][56] = '*';
    field[7][56] = '*';
    field[8][56] = '*';
    field[12][56] = '*';
    field[13][56] = '*';
    field[14][56] = '*';
}

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

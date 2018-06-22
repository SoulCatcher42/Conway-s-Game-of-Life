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

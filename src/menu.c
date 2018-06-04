#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu_print()
{
    system("clear");
    printf("1. Random generation\n");
    printf("2. Pre-set of figures\n");
    printf("3. Reading a figure from a file\n");
}

int check_input(char input[2])
{
    return (input[1] == '\0' && (input[0] >= '1' && input[0] <= '3')) ? 0 : 1;
}

void menu()
{
    menu_print();
    char chose[2];
    while (true) {
        scanf("%s",&chose);
        if (!check_input(chose)) {
            break;
        } else {
            printf("Wrong input, please enter 1-3");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "field.h"
#include "mainloop.h"
#include "preset.h"

void menu_print()
{
    system("clear");
    printf("1. Random generation\n");
    printf("2. Preset of figures\n");
    printf("3. Reading a figure from a file\n");
    printf("4. Exit\n");
}

int check_input(char input[2])
{
    return !(input[1] == '\0' && (input[0] >= '1' && input[0] <= '4'));
}

void menu()
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    while (1) {
        field_init(field);
        menu_print();
        char chose;
        while (1) {
            char temp[2];
            scanf("%s", temp);
            if (!check_input(temp)) {
                chose = temp[0];
                break;
            } else {
                printf("Wrong input, please input 1-4\n");
            }
        }
        switch (chose) {
        case '1':
            random_fill(field);
            mainloop(field);
            break;
        case '2':
            preset_menu(field);
            mainloop(field);
            break;
        case '3':
            // read_file(field);
            mainloop(field);
            break;
        case '4':
            return;
        }
    }
}

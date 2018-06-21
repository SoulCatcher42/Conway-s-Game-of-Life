#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "mainloop.h"
#include "field_print.h"
#include "cell.h"

int live_cells(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    int live = 0;
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            if (field[i][j] == '*') {
                ++live;
            }
        }
    }
    return live;
}

int iteration(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    char current_field[FIELD_HEIGHT][FIELD_WIDTH];
    memcpy(current_field, field, sizeof(current_field));
    field_init(field);
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            if (cell_status(current_field, i, j)) {
                field[i][j] = '*';
            }
        }
    }
    return memcmp(current_field, field, sizeof current_field);
}

void mainloop(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    int gen = 0;
    while (1) {
        int live = live_cells(field);
        system("clear");
        field_print(field, ++gen, live);
        if (!iteration(field)) {
            printf("Field is stable\n");
            printf("Press Enter to continue\n");
            getchar();
        }
        sleep(1);
    }
}

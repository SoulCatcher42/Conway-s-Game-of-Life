#include <stdlib.h>
#include "mainloop.h"
#include "field_print.h"

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

void mainloop(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    int gen = 1;
    while (1) {
        system("clear");
        field_print(field, gen, live)
    }
}

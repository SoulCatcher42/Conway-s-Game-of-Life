#include "field.h"

void field_init(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            field[i][j] = ' ';
        }
    }
}

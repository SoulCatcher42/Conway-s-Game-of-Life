#include <time.h>
#include <stdlib.h>
#include "field.h"

void field_init(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            field[i][j] = ' ';
        }
    }
}

void random_fill(char field[FIELD_HEIGHT][FIELD_WIDTH])
{
    srand(time(NULL));
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            if (rand() % 3 == 0) {
                field[i][j] = '*';
            }
        }
    }
}

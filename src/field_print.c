#include <stdio.h>
#include <stdlib.h>
#include "field_print.h"

void field_print(char field[FIELD_HEIGHT][FIELD_WIDTH], int gen, int live)
{
    system("clear");
    for (int i = 0; i < 68; i++) {
        putchar(' ');
    }
    printf("Generation: %-4d  Live cells: %-4d\n", gen, live);
    for (int i = 0; i < 102; i++) {
        putchar('-');
    }
    putchar('\n');
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        putchar('|');
        for (int j = 0; j < FIELD_WIDTH; j++) {
            printf("%c", field[i][j]);
        }
        printf("|\n");
    }
    for (int i = 0; i < 102; i++) {
        putchar('-');
    }
    putchar('\n');
}

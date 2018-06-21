#pragma once

#include "field.h"

int correcting_coordinate(int coordinate, int limit);
int check_cell(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y);
int neighbors_count(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y);
int cell_status(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y);

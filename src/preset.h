#pragma once

#include "field.h"

void preset_menu_print();
int preset_menu_check_input(char input[2]);
void preset_menu(char field[FIELD_HEIGHT][FIELD_WIDTH]);
void glider(char field[FIELD_HEIGHT][FIELD_WIDTH]);
void glider_gun(char field[FIELD_HEIGHT][FIELD_WIDTH]);
void pulsar(char field[FIELD_HEIGHT][FIELD_WIDTH]);
void spaceship(char field[FIELD_HEIGHT][FIELD_WIDTH);
void pentadecathlon(char field[FIELD_HEIGHT][FIELD_WIDTH]);

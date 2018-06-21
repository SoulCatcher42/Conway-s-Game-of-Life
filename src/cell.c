#include "cell.h"

int correcting_coordinate(int coordinate, int limit)
{
    if (coordinate < 0) {
        coordinate += limit;
    } else if (coordinate >= limit) {
        coordinate -= limit;
    }
    return coordinate;
}

int check_cell(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y)
{
    x = correcting_coordinate(x, FIELD_WIDTH);
    y = correcting_coordinate(y, FIELD_HEIGHT);
    return (field[x][y] == '*') ? 1 : 0;
}

int neighbors_count(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y)
{
    int neighbors = 0;
    neighbors += check_cell(field, x - 1, y - 1);
    neighbors += check_cell(field, x - 1, y    );
    neighbors += check_cell(field, x - 1, y + 1);
    neighbors += check_cell(field, x,     y - 1);
    neighbors += check_cell(field, x,     y + 1);
    neighbors += check_cell(field, x + 1, y - 1);
    neighbors += check_cell(field, x + 1, y    );
    neighbors += check_cell(field, x + 1, y + 1);
    return neighbors;
}

int one_cell_check(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y)
{

}
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
    x = correcting_coordinate(x, FIELD_HEIGHT);
    y = correcting_coordinate(y, FIELD_WIDTH);
    return field[x][y] == '*';
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

int cell_status(char field[FIELD_HEIGHT][FIELD_WIDTH], int x, int y)
{
    int neighbors = neighbors_count(field, x, y);
    return neighbors == 3
            || (neighbors == 2 && check_cell(field, x, y));
}

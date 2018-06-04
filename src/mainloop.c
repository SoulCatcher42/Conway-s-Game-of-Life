#include "mainloop.h"
#include "field.h"
#include "field_print.h"

void mainloop()
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    random_fill(field);
    int gen = 0;
    int live = 0;
    field_print(field, live, gen);
}

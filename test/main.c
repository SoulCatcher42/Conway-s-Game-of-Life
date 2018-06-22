#define CTEST_MAIN

#include <ctest.h>
#include <field.h>
#include <menu.h>
#include <cell.h>
#include <preset.h>

CTEST(field_init, correct)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    int wrong = 0;
    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            if (field[i][j] != ' ') {
                ++wrong;
            }
        }
    }
    int expected = 0;
    ASSERT_EQUAL(expected, wrong);
}

CTEST(field_init, incorrect)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[5][6] = '\0';
    int wrong = 0;
    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            if (field[i][j] != ' ') {
                ++wrong;
            }
        }
    }
    int expected = 1;
    ASSERT_EQUAL(expected, wrong);
}

CTEST(check_input, correct1)
{
    char input[2] = "1";
    int result = check_input(input);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, correct2)
{
    char input[2] = "2";
    int result = check_input(input);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, correct3)
{
    char input[2] = "3";
    int result = check_input(input);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, correct4)
{
    char input[2] = "4";
    int result = check_input(input);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect1)
{
    char input[2] = "0";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect2)
{
    char input[2] = "-1";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect3)
{
    char input[2] = "a";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect4)
{
    char input[2] = "ab";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect5)
{
    char input[2] = "01";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect6)
{
    char input[2] = "5";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect7)
{
    char input[2] = "9";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect8)
{
    char input[2] = "\n";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_input, incorrect9)
{
    char input[2] = "\\";
    int result = check_input(input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, no_correction1)
{
    int result = correcting_coordinate(5, 10);
    int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, no_correction2)
{
    int result = correcting_coordinate(0, 10);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, no_correction3)
{
    int result = correcting_coordinate(9, 10);
    int expected = 9;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, no_correction4)
{
    int result = correcting_coordinate(999, 1000);
    int expected = 999;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, over_limit1)
{
    int result = correcting_coordinate(10, 10);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, over_limit2)
{
    int result = correcting_coordinate(1000, 1000);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, over_limit3)
{
    int result = correcting_coordinate(11, 10);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, over_limit4)
{
    int result = correcting_coordinate(55, 50);
    int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, over_limit5)
{
    int result = correcting_coordinate(30, 10);
    int expected = 20;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, less_than_zero1)
{
    int result = correcting_coordinate(-1, 10);
    int expected = 9;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, less_than_zero2)
{
    int result = correcting_coordinate(-5, 10);
    int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, less_than_zero3)
{
    int result = correcting_coordinate(-1, 1000);
    int expected = 999;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, less_than_zero4)
{
    int result = correcting_coordinate(-10, 10);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(correcting_coordinates, less_than_zero5)
{
    int result = correcting_coordinate(-400, 500);
    int expected = 100;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, correct)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[5][6] = '*';
    int result = check_cell(field, 5, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, several_cells)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[5][6] = '*';
    field[5][7] = '*';
    field[4][6] = '*';
    int result = check_cell(field, 5, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, incorrect)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    int result = check_cell(field, 5, 6);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, over_limit)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[0][0] = '*';
    int result = check_cell(field, FIELD_HEIGHT, FIELD_WIDTH);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, less_than_zero_both)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[FIELD_HEIGHT - 1][FIELD_WIDTH - 1] = '*';
    int result = check_cell(field, -1, -1);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, less_than_zero_x)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[FIELD_HEIGHT - 1][5] = '*';
    int result = check_cell(field, -1, 5);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_cell, less_than_zero_y)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[3][FIELD_WIDTH - 1] = '*';
    int result = check_cell(field, 3, -1);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, count1)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    int result = neighbors_count(field, 5, 5);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, count2)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[4][5] = '*';
    int result = neighbors_count(field, 5, 5);
    int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, count5)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[4][5] = '*';
    field[4][6] = '*';
    field[5][4] = '*';
    field[5][6] = '*';
    int result = neighbors_count(field, 5, 5);
    int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, count9)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[4][5] = '*';
    field[4][6] = '*';
    field[5][4] = '*';
    field[5][6] = '*';
    field[6][4] = '*';
    field[6][5] = '*';
    field[6][6] = '*';
    int result = neighbors_count(field, 5, 5);
    int expected = 8;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, all_cells)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[4][5] = '*';
    field[4][6] = '*';
    field[5][4] = '*';
    field[5][5] = '*';
    field[5][6] = '*';
    field[6][4] = '*';
    field[6][5] = '*';
    field[6][6] = '*';
    int result = neighbors_count(field, 5, 5);
    int expected = 8;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, over_limit)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[FIELD_HEIGHT - 1][FIELD_WIDTH - 1] = '*';
    field[0][FIELD_WIDTH - 1] = '*';
    field[FIELD_HEIGHT - 1][0] = '*';
    int result = neighbors_count(field, 0, 0);
    int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(neighbors_count, less_than_zero)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[0][0] = '*';
    field[0][FIELD_WIDTH - 1] = '*';
    field[FIELD_HEIGHT - 1][0] = '*';
    int result = neighbors_count(field, FIELD_HEIGHT - 1, FIELD_WIDTH - 1);
    int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, still_alive_2n)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[5][5] = '*';
    field[4][5] = '*';
    field[5][6] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, still_alive_3n)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[5][5] = '*';
    field[4][5] = '*';
    field[5][6] = '*';
    field[4][4] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, keep_dead_less_3n)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][5] = '*';
    field[5][6] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, keep_dead_zero)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, keep_dead_more_3n)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][5] = '*';
    field[5][4] = '*';
    field[5][6] = '*';
    field[4][6] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, revival)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][5] = '*';
    field[5][4] = '*';
    field[5][6] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, lonely_death)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[5][5] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, amost_lonely_death)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[5][5] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, overpopulation)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[4][5] = '*';
    field[4][6] = '*';
    field[5][4] = '*';
    field[5][5] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(cell_status, ultra_overpopulation)
{
    char field[FIELD_HEIGHT][FIELD_WIDTH];
    field_init(field);
    field[4][4] = '*';
    field[4][5] = '*';
    field[4][6] = '*';
    field[5][4] = '*';
    field[5][5] = '*';
    field[5][6] = '*';
    field[6][4] = '*';
    field[6][5] = '*';
    field[6][6] = '*';
    int result = cell_status(field, 5, 5);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}

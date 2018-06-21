#define CTEST_MAIN

#include <ctest.h>

#include <field.h>
#include <menu.h>
#include <cell.h>

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
    char input[2] = "4";
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
    int expected = 9;
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

int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}

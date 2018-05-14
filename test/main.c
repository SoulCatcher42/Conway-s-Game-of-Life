#define CTEST_MAIN

#include <ctest.h>

#include <field.h>

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

int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}

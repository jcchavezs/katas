#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

void assert_roman(int actual_as_int, char* expected_as_roman);

int test_convert_into_roman()
{
    int i;
    char *as_roman;

    printf("\n| %8s | %8s | %8s |\n", "Expected", "Actual", "Input");

    assert_roman(1, "I");
    assert_roman(2, "II");
    assert_roman(3, "III");
    assert_roman(4, "IV");
    assert_roman(5, "V");
    assert_roman(6, "VI");
    assert_roman(7, "VII");
    assert_roman(8, "VIII");
    assert_roman(9, "IX");
    assert_roman(10, "X");
    assert_roman(11, "XI");
    assert_roman(12, "XII");
    assert_roman(16, "XVI");
    assert_roman(51, "LI");
    assert_roman(99, "XCIX");
    assert_roman(100, "C");
    assert_roman(101, "CI");
    assert_roman(123, "CXXIII");
    assert_roman(457, "CDLVII");
    assert_roman(999, "CMXCIX");

    return 0;
}

void assert_roman(int actual_as_int, char* expected_as_roman)
{
    char *actual_as_roman;

    actual_as_roman = convert_into_roman(actual_as_int);
    printf("| %8s | %8s | %8d |\n", expected_as_roman, actual_as_roman, actual_as_int);
    assert(strcmp(expected_as_roman, actual_as_roman) == 0);
}
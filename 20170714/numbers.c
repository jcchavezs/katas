#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "numbers.h"

char* concatenate(int num_args, ...);
char* translate_number(int number, char* low, char* mid, char* high);
void not_enough_memory();

char* convert_into_roman(int number)
{
    int ones, tens, hundreds;
    char *as_roman, *as_roman_hundreds, *as_roman_tens, *as_roman_ones;

    hundreds = number % 1000 / 100;
    tens = number % 100 / 10;
    ones = number % 10 / 1;

    as_roman_hundreds = translate_number(hundreds, "C", "D", "M");
    as_roman_tens = translate_number(tens, "X", "L", "C");
    as_roman_ones = translate_number(ones, "I", "V", "X");

    as_roman = (char*) malloc(sizeof(as_roman_ones) + sizeof(as_roman_tens) + sizeof(as_roman_hundreds));
    if (as_roman == NULL) {
        not_enough_memory();
    }

    strcat(as_roman, as_roman_hundreds);
    strcat(as_roman, as_roman_tens);
    strcat(as_roman, as_roman_ones);

    return as_roman;
}

char* translate_number(int number, char* low, char* mid, char* high)
{
    switch (number) {
        case 1:
            return low;
        case 2:
            return concatenate(2, low, low);
        case 3:
            return concatenate(3, low, low, low);
        case 4:
            return concatenate(2, low, mid);
        case 5:
            return concatenate(1, mid);
        case 6:
            return concatenate(2, mid, low);
        case 7:
            return concatenate(3, mid, low, low);
        case 8:
            return concatenate(4, mid, low, low, low);
        case 9:
            return concatenate(2, low, high);
    }

    return "";
}

char* concatenate(int num_args, ...)
{
    char *concat_output;
    va_list pieces;
    int i;

    concat_output = (char*) malloc(num_args * sizeof(char));
    if (concat_output == NULL) {
        not_enough_memory();
    }

    va_start(pieces, num_args);
    for (i = 0; i < num_args; i++) {
        strcat(concat_output, va_arg(pieces, char*));
    }
    va_end(pieces);

    return concat_output;
}

void not_enough_memory()
{
    printf("Not enough memory.");
    exit(1);
}
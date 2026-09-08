#ifndef MINILIB_H_
#define MINILIB_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef MLDEF
#define MLDEF static inline
#endif // MLDEF

MLDEF int array_min(int array[], int length);
MLDEF int array_max(int array[], int length);
MLDEF char *str_reverse(char string[]);
MLDEF int ascii_to_int(char string[]);
MLDEF bool is_ascii_digit(int code);

#define ASCII_MIN_DIGIT 48
#define ASCII_MAX_DIGIT 57
#define ASCII_SPACE 32
#define ASCII_PLUS 43
#define ASCII_MINUS 45

#endif // MINILIB_H_

#ifdef MINILIB_IMPLEMENTATION

// Returns the smallest value within an integer array
MLDEF int array_min(int array[], int length)
{
    int minimum = array[0];

    for (int i = 1; i < length; i++)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }

    return minimum;
}

// Returns the largest value within an integer array
MLDEF int array_max(int array[], int length)
{
    int maximum = array[0];

    for (int i = 1; i < length; i++)
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
        }
    }

    return maximum;
}

// Reverses the order of all characters in a string and returns it
MLDEF char *str_reverse(char string[])
{
    int left = 0;
    int right = strlen(string) - 1;

    while (left < right)
    {
        char left_temp = string[left];
        string[left] = string[right];
        string[right] = left_temp;

        left += 1;
        right -= 1;
    }

    return string;
}

// Checks if an ASCII code corresponds to a digit
MLDEF bool is_ascii_digit(int code)
{
    return ASCII_MIN_DIGIT <= code && code <= ASCII_MAX_DIGIT;
}

// Converts a string into its equivalent integer value
MLDEF int ascii_to_int(char string[])
{
    int result = 0;
    int current_code = 0;
    int next_code = 0;
    int sign = 1;
    const int base = 10;

    for (int i = 0; i < strlen(string); i++)
    {
        current_code = (int)string[i];
        next_code = (int)string[i + 1];

        if (is_ascii_digit(current_code))
        {
            result *= base;
            result += current_code - ASCII_MIN_DIGIT;

            if (!(is_ascii_digit(next_code)))
            {
                break;
            }
        }
        else
        {
            if (current_code == ASCII_PLUS || current_code == ASCII_MINUS)
            {
                if (!(is_ascii_digit(next_code)))
                {
                    return 0;
                }

                if (current_code == ASCII_MINUS)
                {
                    sign = -1;
                }
            }
            else if (!(current_code == ASCII_SPACE))
            {
                return 0;
            }
        }
    }

    return result * sign;
}

#endif // MINILIB_IMPLEMENTATION
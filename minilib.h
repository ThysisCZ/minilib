#ifndef MINILIB_H_
#define MINILIB_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>

#ifndef MLDEF
#define MLDEF static inline
#endif // MLDEF

MLDEF int array_min(int array[], int length);
MLDEF int array_max(int array[], int length);
MLDEF char *str_reverse(char string[]);
MLDEF int ascii_to_int(char string[]);
MLDEF bool is_ascii_digit(int code);
MLDEF char *dec_to_binary(int decimal, char buffer[], size_t buffer_size);

#define ASCII_MIN_DIGIT 48
#define ASCII_MAX_DIGIT 57
#define ASCII_SPACE 32
#define ASCII_PLUS 43
#define ASCII_MINUS 45

#define PLUS_SIGN 1
#define MINUS_SIGN -1

#define BINARY_BUFFER_LENGTH 17
#define MIN_DECIMAL_TO_BINARY -32768
#define MAX_DECIMAL_TO_BINARY 32767

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
    int sign = PLUS_SIGN;
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
                    sign = MINUS_SIGN;
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

// Returns the binary representation of a decimal numeral as a string
MLDEF char *dec_to_binary(int decimal, char buffer[], size_t buffer_size)
{
    if (!(MIN_DECIMAL_TO_BINARY <= decimal && decimal <= MAX_DECIMAL_TO_BINARY))
    {
        assert(0 && "Decimal value is out of allowed range <-32768; 32767>");
        return NULL;
    }

    if (buffer_size < BINARY_BUFFER_LENGTH)
    {
        assert(0 && "The buffer size must be at least 17 bytes");
        return NULL;
    }

    int16_t short_dec = decimal;
    const char values[] = "01";
    int low_pow_bound = 0;
    int remainder = 0;
    int sign = short_dec / abs(short_dec);

    int start = 0;
    int end = buffer_size - 2;

    if (sign == PLUS_SIGN)
    {
        if (short_dec != 0 && (short_dec & (short_dec - 1)) == 0)
        {
            for (int i = end; i >= start; i--)
            {
                if (short_dec >> 1 == 0)
                {
                    buffer[i] = values[1];
                    break;
                }
                else
                {
                    short_dec >>= 1;
                }
            }
        }
        else
        {
            low_pow_bound = 1 << (int)log2(short_dec);
            remainder = short_dec - low_pow_bound;

            dec_to_binary(low_pow_bound, buffer, buffer_size);
            dec_to_binary(remainder, buffer, buffer_size);
        }
    }
    else
    {
        dec_to_binary(abs(short_dec) - 1, buffer, buffer_size);

        for (int i = start; i <= end; i++)
        {
            if (buffer[i] == values[0])
            {
                buffer[i] = values[1];
            }
            else
            {
                buffer[i] = values[0];
            }
        }
    }

    return buffer;
}

#endif // MINILIB_IMPLEMENTATION
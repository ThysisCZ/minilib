#ifndef MINILIB_H_
#define MINILIB_H_

#include <stdio.h>
#include <stdbool.h>

#ifndef MLDEF
#define MLDEF static inline
#endif // MLDEF

MLDEF int arr_min(int array[], int length);
MLDEF int arr_max(int array[], int length);

#endif // MINILIB_H_

#ifdef MINILIB_IMPLEMENTATION

MLDEF int arr_min(int array[], int length)
{
    int minimum = array[0];

    for (int i = 0; i < length; i++)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }

    return minimum;
}

MLDEF int arr_max(int array[], int length)
{
    int maximum = array[0];

    for (int i = 0; i < length; i++)
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
        }
    }

    return maximum;
}

#endif // MINILIB_IMPLEMENTATION
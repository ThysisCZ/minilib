#define MINILIB_IMPLEMENTATION
#include "minilib.h"

#define ARRAY_LENGHT(array) ((int)(sizeof(array) / sizeof(array[0])))

int main()
{
    int array[5] = {3, 4, 0, -2, -1};

    int min = arr_min(array, ARRAY_LENGHT(array));
    printf("%d\n", min);

    int max = arr_max(array, ARRAY_LENGHT(array));
    printf("%d\n", max);

    return 0;
}
#define MINILIB_IMPLEMENTATION
#include "minilib.h"

#define ARRAY_LENGHT(array) (sizeof(array) / sizeof(array[0]))

int main()
{
    int array1[5] = {4, 3, 0, -2, -1};

    int min = array_min(array1, ARRAY_LENGHT(array1));
    printf("%d\n", min);

    int max = array_max(array1, ARRAY_LENGHT(array1));
    printf("%d\n", max);

    char string1[] = "abcdefg";

    char *reversed = str_reverse(string1);
    printf("%s\n", reversed);

    char string2[] = "   -123abc4";

    int integer = ascii_to_int(string2);
    printf("%d\n", integer);

    int decimal = -256;
    char buffer1[] = "0000000000000000";

    printf("%s\n", dec_to_binary(decimal, buffer1, sizeof(buffer1)));

    return 0;
}
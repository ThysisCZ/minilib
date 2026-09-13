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

    char buffer1[] = "0000000000000000";
    const char *null_binary = "0000000000000000";

    const int start = 0;
    const int end = 8;

    for (int i = start; i <= end; i++)
    {
        printf("%s\n", dec_to_binary(i, buffer1, sizeof(buffer1)));
        strcpy(buffer1, null_binary);
    }

    return 0;
}
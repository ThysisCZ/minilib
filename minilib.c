#define MINILIB_IMPLEMENTATION
#include "minilib.h"

int main()
{
    const char *message = hello_world();
    printf("%s", message);

    return 0;
}
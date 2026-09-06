#ifndef MINILIB_H_
#define MINILIB_H_

#include <stdio.h>

#ifndef MLDEF
#define MLDEF static inline
#endif // MLDEF

MLDEF const char *hello_world();

#endif // MINILIB_H_

#ifdef MINILIB_IMPLEMENTATION

MLDEF const char *hello_world()
{
    const char *message = "Hello world!";
    return message;
}

#endif // MINILIB_IMPLEMENTATION
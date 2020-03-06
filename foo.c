#include <stdio.h>
#include "foo.h"

int foo(const int x) {
    const int y = x + 1;

    printf("libfoo: %d => %d\n", x, y);

    return y;
}

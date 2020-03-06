#include <stdio.h>
#include "foo.h"

int foo(const int x) {
    const int y = x + 10;

    printf("libbar: %d -> %d\n", x, y);

    return y;
}

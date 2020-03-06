#include <stdio.h>
#include <foo.h>

int main(int argc, char* argv[]) {
    const int n = 11;

    printf("foo(%d) = %d\n", n, foo(n));

    return 0;
}

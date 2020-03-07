#include <stdio.h>
#include <foo.h>

int main(int argc, char* argv[]) {
    const int n = 11;

    for (int i = 0; i < argc; i++) {
        printf("arg: %s\n", argv[i]);
    }

    printf("foo(%d) = %d\n", n, foo(n));

    return 0;
}

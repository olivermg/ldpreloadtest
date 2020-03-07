#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROGRAM "prg"
#define LIB "libbar.so"

int main(int argc, char* argv[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // child
        argv[0] = PROGRAM;
        static char *env[] = {
            "LD_LIBRARY_PATH=.",
            "LD_PRELOAD=" LIB,
            NULL
        };
        execve("./" PROGRAM, argv, env);
        exit(127);
    } else {
        // parent
        printf("=== waiting for child...\n");
        waitpid(pid, 0, 0);
        printf("=== done.\n");
    }

    return 0;
}

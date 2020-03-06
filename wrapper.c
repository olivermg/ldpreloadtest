#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // child
        static char *argv[] = {
            "prg",
            NULL
        };
        static char *env[] = {
            "LD_LIBRARY_PATH=.",
            "LD_PRELOAD=libbar.so",
            NULL
        };
        execve("./prg", argv, env);
        exit(127);
    } else {
        // parent
        printf("=== waiting for child...\n");
        waitpid(pid, 0, 0);
        printf("=== done.\n");
    }

    return 0;
}

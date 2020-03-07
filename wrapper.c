#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STRINGIFY(x) #x
#define STRING(x) STRINGIFY(x)

#ifndef LDPRELOAD
#error *** please define LDPRELOAD ***
#endif

#ifndef PROGRAM
#error *** please define PROGRAM ***
#endif

int main(int argc, char* argv[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // child
        static char *env[] = {
            NULL,
            NULL,
            NULL
        };

        char ldpreload[] = "LD_PRELOAD=" STRING(LDPRELOAD);
        printf("===c %s\n", ldpreload);
        env[0] = ldpreload;

#ifdef LDLIBPATH
        char ldlibrarypath[] = "LD_LIBRARY_PATH=" STRING(LDLIBPATH);
        env[1] = ldlibrarypath;
        printf("===c %s\n", ldlibrarypath);
#endif

        char program[] = STRING(PROGRAM);
        argv[0] = program;
        printf("===c %s\n", program);

        execve(program, argv, env);
        exit(127);
    } else {
        // parent
        printf("===p waiting for child...\n");
        waitpid(pid, 0, 0);
        printf("===p done.\n");
    }

    return 0;
}

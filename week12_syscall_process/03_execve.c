#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:./03_exeve <program path> [OPTION]...\n");
        return 0;
    }
    
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) {
        execve(argv[1], &argv[1], NULL);

        perror(argv[1]);
        return 1;
    }
    else {
        int watastus;

        waitpid(child_pid, &watastus, 0);

        if (WIFEXITED(watastus)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(watastus));
        }

    }

}
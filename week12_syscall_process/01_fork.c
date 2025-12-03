#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

int main(void) {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) {
        printf("Child process PID: %d\n", getpid());
        printf("Child process PPID: %d\n", getppid());

        return 7;
    }
    else {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);

        if(WIFEXITED(wstatus)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }

        printf("Parent process PID: %d\n", getpid());
        printf("Parent process PPID: %d\n", getppid());
    }

    return 0;

}
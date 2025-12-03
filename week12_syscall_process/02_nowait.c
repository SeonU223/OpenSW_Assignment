#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>

int main(void) {
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) {
        sleep(1);

        printf("Child process PID: %d\n", getpid());
        printf("Child process PPID: %d\n", getppid());
    }
    else {
        printf("Parent process PID: %d\n", getpid());
        printf("Parent process PPID: %d\n", getppid());
    }

    return 0;

}
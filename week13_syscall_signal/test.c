#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>


void sigint_handler(int sig) {
    char *argv[] = {"ls", NULL};
    printf("[SIGINT handler] ----------\n"); 

    pid_t pid = fork();
    int watatus;
    if (pid == 0) { // child
        execve("/usr/bin/ls", argv, NULL);
    }
    else { // parent
        waitpid(pid, &watatus, 0);
    }
}

void sigquit_handler(int sig) {
    char *argv[] = {"date", NULL};
    printf("[SIGQUIT handler] ----------\n");

    pid_t pid = fork();
    int watatus;
    if (pid == 0) { // child
        execve("/usr/bin/date", argv, NULL);
    }
    else { // parent
        waitpid(pid, &watatus, 0);
    }
}

void sigalarm_handler(int sig) {
    char *argv[] = {"whoami", NULL};
    printf("[SIGALRM handler] ----------\n"); 

    pid_t pid = fork();
    int watatus;
    if (pid == 0) { // child
        execve("/usr/bin/whoami", argv, NULL);
    }
    else { // parent
        waitpid(pid, &watatus, 0);
        alarm(3);
    }    
}


int main(void) {
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalarm_handler);

    alarm(3);

    while (1) {
        sleep(1);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

struct two_double {
    double a;
    double b;
} data;

void sigalarm_handler(int sig) {
    printf("\n%f, %f\n", data.a, data.b); 
    alarm(1);
}


int main(void) {
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};
    struct sigaction sa_alarm;

    sa_alarm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;

    if(sigaction(SIGALRM, &sa_alarm, NULL) == -1) {
        perror("sigaction error: ");
        exit(0);
    }

    sigset_t block_set;
    
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);

    alarm(1);

    //SIGPROCMASK

    while (1) {
        // 1
        sigprocmask(SIG_BLOCK, &block_set, NULL);

        data = ones;

        // unser
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);

        // 0
        sigprocmask(SIG_BLOCK, &block_set, NULL);
        
        data = zeros;
        // unset
        sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    }

    return 0;
}
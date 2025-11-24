#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main(void) {
    pid_t my_pid = getpid();
    pid_t my_ppid = getppid();

    printf("mypid : %d\n", my_pid);
    printf("myppid: %d\n", my_ppid);

    return 0;
}
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main(void) {
    pid_t my_pid = getpid();

    printf("mypid: %d\n", my_pid);

    return 0;
}
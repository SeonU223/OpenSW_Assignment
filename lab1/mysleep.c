#include <unistd.h>
#include <stdio.h>

int main(void) {
    for (;;) {
        sleep(3);
        printf("hello sleeping you!\n");
        fflush(stdout);
    }   
    return 0;
}
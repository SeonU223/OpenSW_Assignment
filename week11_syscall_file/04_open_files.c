#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("plz arguments.\n");
        return 0;
    }

    for (int i = 0; i < argc; i++) {
        int my_file = open(argv[i], O_RDONLY);

        if (my_file == -1) {
            perror(argv[i]);               
            continue;                      
        }

        printf("open success: %s (fd = %d)\n", argv[i], my_file);

        if (close(my_file) == -1) {
            perror("close");
        } else {
            printf("close success: %s\n", argv[i]);
        }
    }

    return 0;
}

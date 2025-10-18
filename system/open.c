#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>  // for strerror()
#include <unistd.h>


int main(void) {
    int fd = open("newFile.txt", O_RDWR | O_CREAT , 0777);
    if (fd == -1) {
        // Print readable error message
        printf("File open error (%d): %s\n", errno, strerror(errno));
        // Or simply:
       perror("open");
    } else {
        printf("File opened successfully. File descriptor: %d\n", fd);
    }
    return 0;
}

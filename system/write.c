#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    // Open (or create) the file in write-only mode
    int fd = open("newFile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    const char *text = "hello world";
    ssize_t bytesWritten = write(fd, text, strlen(text));

    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Successfully wrote %zd bytes to file.\n", bytesWritten);

    close(fd);
    return 0;
}

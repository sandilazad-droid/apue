#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("newFile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Move to byte 6 (skips "hello ")
    off_t pos = lseek(fd, 6, SEEK_SET);
    if (pos == -1) {
        perror("lseek");
        return 1;
    }

    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("read");
        return 1;
    }

    buffer[bytesRead] = '\0';
    printf("Data from byte 6: %s\n", buffer);

    close(fd);
    return 0;
}

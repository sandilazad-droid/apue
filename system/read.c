// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <errno.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int main(void) {
//     int fd = open("newFile.txt", O_RDONLY);
//     if (fd == -1) {
//         printf("Error opening file (%d): %s\n", errno, strerror(errno));
//         return 1;
//     }

//     char buffer[101];  // extra byte for null-terminator
//     ssize_t bytesRead = read(fd, buffer, 100);

//     if (bytesRead == -1) {
//         printf("Error reading file (%d): %s\n", errno, strerror(errno));
//         close(fd);
//         return 1;
//     }

//     buffer[bytesRead] = '\0';  // null-terminate the string
//     printf("Read %zd bytes:\n%s\n", bytesRead, buffer);

//     close(fd);
//     return 0;
// }


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024  // read in 1 KB chunks

int main(void) {
    int fd = open("newFile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE + 1];  // +1 for null-terminator
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytesRead] = '\0';  // Null-terminate so we can print it
        printf("%s", buffer);
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

   printf("Read %zu bytes\n", sizeof(buffer));


    close(fd);
    return 0;
}

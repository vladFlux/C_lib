#include "io_utils.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>


ssize_t vladutz_read(int fd, void *buffer, size_t count) {
    ssize_t bytesRead = 0;
    ssize_t result;

    while (count > 0) {
        result = syscall(SYS_read, fd, buffer, count);
        if (result < 0) {
            if (errno == EINTR) {
                continue;
            }
            return -1;
        }
        if (result == 0) {
            break;
        }
        bytesRead += result;
        buffer = (char *) buffer + result;
        count -= result;
    }

    return bytesRead;
}

ssize_t vladutz_write(int fd, const void *buffer, size_t count) {
    ssize_t bytesWritten = 0;
    ssize_t result;

    while (count > 0) {
        result = syscall(SYS_write, fd, buffer, count);
        if (result < 0) {
            if (errno == EINTR) {
                continue;
            }
            return -1;
        }
        bytesWritten += result;
        buffer = (const char *) buffer + result;
        count -= result;
    }

    return bytesWritten;
}

int vladutz_open(const char *pathname, int flags, mode_t mode) {
    int fd = syscall(SYS_open, pathname, flags, mode);
    if (fd < 0) {
        perror("vladutz_open");
    }
    return fd;
}

int vladutz_close(int fd) {
    int result = syscall(SYS_close, fd);
    if (result < 0) {
        perror("vladutz_close");
    }
    return result;
}

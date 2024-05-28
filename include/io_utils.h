#ifndef OS_2_PROJECT_IO_UTILS_H
#define OS_2_PROJECT_IO_UTILS_H

#include <stddef.h>
#include <unistd.h>

ssize_t vladutz_read(int fd, void *buffer, size_t count);

ssize_t vladutz_write(int fd, const void *buffer, size_t count);

int vladutz_open(const char *pathname, int flags, mode_t mode);

int vladutz_close(int fd);

#endif //OS_2_PROJECT_IO_UTILS_H

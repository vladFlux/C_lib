#ifndef OS_2_PROJECT_STRING_UTILS_H
#define OS_2_PROJECT_STRING_UTILS_H

#include <stddef.h>

char *vladutz_strcat(char *dest, const char *src);

char *vladutz_substr(const char *str, size_t start, size_t length);

char *vladutz_strstr(const char *haystack, const char *needle);

int vladutz_snprintf(char *buffer, size_t size, const char *format, ...);

#endif //OS_2_PROJECT_STRING_UTILS_H

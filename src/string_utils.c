#include "string_utils.h"


char *vladutz_strcat(char *dest, const char *src) {
    char *dest_ptr = dest + strlen(dest);
    while (*src != '\0') {
        *dest_ptr++ = *src++;
    }
    *dest_ptr = '\0';
    return dest;
}

char *vladutz_substr(const char *str, size_t start, size_t length) {
    if (start + length > strlen(str)) {
        return NULL;
    }

    char *substr = (char *) malloc((length + 1) * sizeof(char));
    if (!substr) {
        return NULL;
    }

    strncpy(substr, str + start, length);
    substr[length] = '\0';
    return substr;
}

char *vladutz_strstr(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char *) haystack;
    }

    for (; *haystack; haystack++) {
        if ((*haystack == *needle) && (strncmp(haystack, needle, strlen(needle)) == 0)) {
            return (char *) haystack;
        }
    }
    return NULL;
}

int vladutz_snprintf(char *buffer, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = vsnprintf(buffer, size, format, args);
    va_end(args);
    return result;
}

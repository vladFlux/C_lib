#ifndef OS_2_PROJECT_MEM_MANAGE_H
#define OS_2_PROJECT_MEM_MANAGE_H

#include <stddef.h>

void *vladutz_malloc(size_t size);

void *vladutz_calloc(size_t num, size_t size);

void *vladutz_realloc(void *ptr, size_t size);

void vladutz_free(void *ptr);

#endif //OS_2_PROJECT_MEM_MANAGE_H

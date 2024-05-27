#ifndef OS_2_PROJECT_MEM_MANAGE_H
#define OS_2_PROJECT_MEM_MANAGE_H

#include <unistd.h>
#include <stddef.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    int free;
} Block;

#define BLOCK_SIZE sizeof(Block)

Block *free_list = NULL;

Block *find_free_block(Block **last, size_t size);

Block *request_space(Block *last, size_t size);

void *vladutz_malloc(size_t size);

void vladutz_free(void *ptr);

#endif //OS_2_PROJECT_MEM_MANAGE_H

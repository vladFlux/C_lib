#include "mem_manage.h"
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>


typedef struct Block {
    size_t size;
    struct Block *next;
    int free;
} Block;

#define BLOCK_SIZE sizeof(Block)

static Block *free_list = NULL;

Block *find_free_block(Block **last, size_t size) {
    Block *current = free_list;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

Block *request_space(Block *last, size_t size) {
    Block *block = (Block *) mmap(NULL, size + BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (block == MAP_FAILED) {
        return NULL;
    }

    if (last) {
        last->next = block;
    }

    block->size = size;
    block->next = NULL;
    block->free = 0;
    return block;
}

void *vladutz_malloc(size_t size) {
    Block *block;

    if (size <= 0) {
        return NULL;
    }

    if (!free_list) {
        block = request_space(NULL, size);
        if (!block) {
            return NULL;
        }
        free_list = block;
    } else {
        Block *last = free_list;
        block = find_free_block(&last, size);
        if (!block) {
            block = request_space(last, size);
            if (!block) {
                return NULL;
            }
        } else {
            block->free = 0;
        }
    }

    return (block + 1);
}

void *vladutz_calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    void *ptr = vladutz_malloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

void *vladutz_realloc(void *ptr, size_t size) {
    if (!ptr) {
        return vladutz_malloc(size);
    }

    Block *block = (Block *) ptr - 1;
    if (block->size >= size) {
        return ptr;
    }

    void *new_ptr = vladutz_malloc(size);
    if (new_ptr) {
        memcpy(new_ptr, ptr, block->size);
        vladutz_free(ptr);
    }
    return new_ptr;
}

void vladutz_free(void *ptr) {
    if (!ptr) {
        return;
    }

    Block *block = (Block *) ptr - 1;
    block->free = 1;
}

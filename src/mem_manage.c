#include "mem_manage.h"


Block *find_free_block(Block **last, size_t size) {
    Block *current = free_list;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

Block *request_space(Block *last, size_t size) {
    Block *block = sbrk(0);
    void *request = sbrk(size + BLOCK_SIZE);
    if (request == (void *) -1) {
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

void vladutz_free(void *ptr) {
    if (!ptr) {
        return;
    }

    Block *block = (Block *) ptr - 1;
    block->free = 1;
}
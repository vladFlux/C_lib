#ifndef OS_2_PROJECT_THREADING_H
#define OS_2_PROJECT_THREADING_H

#include <stddef.h>

typedef struct {
    void *(*start_routine)(void *);

    void *arg;
    int thread_id;
} vladutz_thread_t;

typedef struct {
    int locked;
} vladutz_mutex_t;

int vladutz_create_thread(vladutz_thread_t *thread, void *(*start_routine)(void *), void *arg);

int vladutz_join_thread(vladutz_thread_t *thread, void **retval);

void vladutz_mutex_init(vladutz_mutex_t *mutex);

void vladutz_mutex_lock(vladutz_mutex_t *mutex);

void vladutz_mutex_unlock(vladutz_mutex_t *mutex);

#endif //OS_2_PROJECT_THREADING_H

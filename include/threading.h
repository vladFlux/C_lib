#ifndef THREAD_UTILS_H
#define THREAD_UTILS_H

#include <pthread.h>


typedef struct {
    pthread_t tid;

    void *(*start_routine)(void *);

    void *arg;
} vladutz_thread_t;

typedef struct {
    int locked;
} vladutz_mutex_t;

int vladutz_create_thread(vladutz_thread_t *thread, void *(*start_routine)(void *), void *arg);

int vladutz_join_thread(vladutz_thread_t *thread, void **retval);

void vladutz_mutex_init(vladutz_mutex_t *mutex);

void vladutz_mutex_lock(vladutz_mutex_t *mutex);

void vladutz_mutex_unlock(vladutz_mutex_t *mutex);

#endif // THREAD_UTILS_H

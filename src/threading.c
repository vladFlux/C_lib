#include "threading.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>


static void *vladutz_thread_entry(void *arg) {
    vladutz_thread_t *thread = (vladutz_thread_t *) arg;
    return thread->start_routine(thread->arg);
}

int vladutz_create_thread(vladutz_thread_t *thread, void *(*start_routine)(void *), void *arg) {
    thread->start_routine = start_routine;
    thread->arg = arg;

    if (pthread_create(&thread->tid, NULL, vladutz_thread_entry, thread) != 0) {
        perror("pthread_create");
        return -1;
    }

    return 0;
}

int vladutz_join_thread(vladutz_thread_t *thread, void **retval) {
    return pthread_join(thread->tid, retval);
}

void vladutz_mutex_init(vladutz_mutex_t *mutex) {
    mutex->locked = 0;
}

void vladutz_mutex_lock(vladutz_mutex_t *mutex) {
    while (__sync_lock_test_and_set(&mutex->locked, 1)) {
        syscall(SYS_sched_yield);
    }
}

void vladutz_mutex_unlock(vladutz_mutex_t *mutex) {
    __sync_lock_release(&mutex->locked);
}

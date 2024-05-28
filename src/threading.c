#include "threading.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define STACK_SIZE 65536


static void vladutz_thread_entry(int tid, void *(*start_routine)(void *), void *arg) {
    start_routine(arg);
    syscall(SYS_exit, 0);
}

int vladutz_create_thread(vladutz_thread_t *thread, void *(*start_routine)(void *), void *arg) {
    void *stack = malloc(STACK_SIZE);
    if (stack == NULL) {
        perror("malloc");
        return -1;
    }

    int tid = clone(vladutz_thread_entry, (char *) stack + STACK_SIZE,
                    CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD, thread->thread_id, start_routine,
                    arg);
    if (tid == -1) {
        perror("clone");
        free(stack);
        return -1;
    }

    thread->thread_id = tid;
    return 0;
}

int vladutz_join_thread(vladutz_thread_t *thread, void **retval) {
    return waitpid(thread->thread_id, NULL, 0);
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

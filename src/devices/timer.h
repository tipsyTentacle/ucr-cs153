#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>
#include "threads/thread.h"

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

struct thread_timer
  {
    /* Pointer to the sleeping thread */
    struct thread *sleeping_thread;
    /* How long the thread is supposed to sleep */
    int64_t ticks;
    /* When the timer was started */
    int64_t start;
    /* Shared between thread.c and synch.c. */
    struct list_elem elem;              /* List element. */
  };
  
struct thread_timer create_timer (struct thread* i_thread, int64_t ticks);
void destroy_thread_timer (struct thread_timer* timer);

void check_sleeping_threads (void);

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

#endif /* devices/timer.h */

#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include "threads/synch.h"

#define MAX_ARGV 40
#define ARGV_DELIMIT " "
/* Struct used to share between process_execute() in the
 *   invoking thread and start_process() inside the newly invoked
 *   thread. */
struct exec_helper 
{
  const char *cmd_line;    //## Program to load (entire command line)
  struct lock *exec_lock;//##Add semaphore for loading (for resource race cases!)
  bool success; //##Add bool for determining if program loaded successfully
  //## Add other stuff you need to transfer between process_execute and process_start (hint, think of the children... need a way to add to the child's list, see below about thread's child list.)
};

struct process_thread_struct
{
  struct thread *data;
  struct list_elem elem;
};

tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);
void init_exec_helper (struct exec_helper *exec, char *file_name, bool success);

#endif /* userprog/process.h */

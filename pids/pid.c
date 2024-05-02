#include <linux/kthread.h>
#include <linux/sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Função da thread
int thread_fn(void *data) {
  printk("Thread PID: %d\n", current->pid);
  return 0;
}

int main() {
  struct task_struct *thread1;

  // Criação da thread
  thread1 = kthread_create(thread_fn, NULL, "thread1");
  if (thread1) {
    wake_up_process(thread1);
    kthread_stop(thread1);
  }

  return 0;
}


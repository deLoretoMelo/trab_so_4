#define MODULE
#define LINUX

#include <linux/kernel.h> /* Needed for KERN_ALERT */
#include <linux/module.h> /* Needed by all modules */

int __init hello_init(void) {
  printk(KERN_ALERT "<1>Hello world 1.\n");
  /* A non-zero return means init_module failed; module can't be loaded. */
  return 0;
}

void __exit goodbye_exit(void) { printk(KERN_ALERT "Goodbye world 1.\n"); }

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(goodbye_exit);
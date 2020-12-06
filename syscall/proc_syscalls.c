#include <types.h>
#include <lib.h>
#include <kern/unistd.h>
#include <syscall.h>
#include <proc.h>
#include <thread.h>
#include <addrspace.h>
void sys__exit(int status) {
    struct addrspace *as = proc_getas();
    as_destroy(as);
    thread_exit();

    panic("thread_exit returned (this should not be seen)\n");
    (void)status;
}
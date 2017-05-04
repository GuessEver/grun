//
// Created by guessever on 5/4/17.
//
// This file is copied from HUSTOJ.
//

#ifndef GRUN_OKCALLS64_H
#define GRUN_OKCALLS64_H

#include <syscall.h>

unsigned OKCALL_PASCAL[] = {0,1,2,3,4,9,11,13,16,59,89,97,201,231,SYS_open, SYS_set_thread_area, SYS_brk, SYS_read,
                          SYS_uname, SYS_write, SYS_execve, SYS_ioctl, SYS_readlink, SYS_mmap,
                          SYS_rt_sigaction, SYS_getrlimit, 252, 191, 158, 231, SYS_close,
                          SYS_exit_group, SYS_munmap, SYS_time, 4, 9999 };
unsigned OKCALL_C[] = {0, 1, 2, 4, 5, 9, 11, 12, 21, 59, 63, 89, 158, 231, 240, 8, SYS_time, SYS_read, SYS_uname, SYS_write, SYS_open,
                    SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_munmap, SYS_mprotect,
                    SYS_mmap, SYS_fstat, SYS_set_thread_area, 252, SYS_arch_prctl, 231, 9999 };
unsigned OKCALL_JAVA[] = { 0,2,3,4,5,9,10,11,12,13,14,21,56,59,89,97,104,158,202,218,231,273,257,
                     61, 22, 6, 33, 8, 13, 16, 111, 110, 39, 79, SYS_fcntl,
                     SYS_getdents64, SYS_getrlimit, SYS_rt_sigprocmask, SYS_futex, SYS_read,
                     SYS_mmap, SYS_stat, SYS_open, SYS_close, SYS_execve, SYS_access,
                     SYS_brk, SYS_readlink, SYS_munmap, SYS_close, SYS_uname, SYS_clone,
                     SYS_uname, SYS_mprotect, SYS_rt_sigaction, SYS_getrlimit, SYS_fstat,
                     SYS_getuid, SYS_getgid, SYS_geteuid, SYS_getegid, SYS_set_thread_area,
                     SYS_set_tid_address, SYS_set_robust_list, SYS_exit_group, 158, 9999 };
unsigned OKCALL_PYTHON[] = { 0,32,72,131,1,2,3,4,5,6,8,9,10,11,12,13,14,16,21,59,78,79,89,97,102,104,107,108,158,202,218,231,257,273
        , 41, 42, 146, SYS_mremap, 158, 117, 60, 39, 102, 191,
                     SYS_access, SYS_arch_prctl, SYS_brk, SYS_close, SYS_execve,
                     SYS_exit_group, SYS_fcntl, SYS_fstat, SYS_futex, SYS_getcwd,
                     SYS_getdents, SYS_getegid, SYS_geteuid, SYS_getgid, SYS_getrlimit,
                     SYS_getuid, SYS_ioctl, SYS_lseek, SYS_lstat, SYS_mmap, SYS_mprotect,
                     SYS_munmap, SYS_open, SYS_read, SYS_readlink, SYS_rt_sigaction,
                     SYS_rt_sigprocmask, SYS_set_robust_list, SYS_set_tid_address, SYS_stat,
                     SYS_write, 9999 };
unsigned OKCALL_LUA[]={0,1,2,3,4,5,9,10,11,12,13,21,59,158,231,292,9999};

#endif //GRUN_OKCALLS64_H

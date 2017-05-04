//
// Created by guessever on 5/4/17.
//
// This file is copied from HUSTOJ.
//

#ifndef GRUN_OKCALLS32_H
#define GRUN_OKCALLS32_H

#include <syscall.h>

unsigned OKCALL_PASCAL[256] = { 0,9, 59, 97, 13, 16, 89, 140, 91, 175, 195, 13, SYS_open, SYS_set_thread_area,
                           SYS_brk, SYS_read, SYS_uname, SYS_write, SYS_execve, SYS_ioctl,
                           SYS_readlink, SYS_mmap, SYS_rt_sigaction, SYS_getrlimit, 252, 191, 0 };
unsigned OKCALL_C[256] = {85, 8, 140, SYS_time, SYS_read, SYS_uname, SYS_write, SYS_open,
                    SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_munmap, SYS_mprotect,
                    SYS_mmap2, SYS_fstat64, SYS_set_thread_area, 252, 0 };
unsigned OKCALL_JAVA[256] = { 295, SYS_fcntl64, SYS_getdents64, SYS_ugetrlimit,
                     SYS_rt_sigprocmask, SYS_futex, SYS_read, SYS_mmap2, SYS_stat64,
                     SYS_open, SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_readlink,
                     SYS_munmap, SYS_close, SYS_uname, SYS_clone, SYS_uname, SYS_mprotect,
                     SYS_rt_sigaction, SYS_sigprocmask, SYS_getrlimit, SYS_fstat64,
                     SYS_getuid32, SYS_getgid32, SYS_geteuid32, SYS_getegid32,
                     SYS_set_thread_area, SYS_set_tid_address, SYS_set_robust_list,
                     SYS_exit_group, 0 };
unsigned OKCALL_PYTHON[256]={3,4,5,6,11,13,33,41,45,54,85,91,102,122,125,140,174,175,
                  183,186,191,192,195,196,197,199,200,201,202,220,221,
                  240,243,252,258,295,311,0};
unsigned OKCALL_LUA[256]={3,4,5,6,11,13,33,45,91,125,174,192,195,197,243,252,330,0};

#endif //GRUN_OKCALLS32_H

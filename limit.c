//
// Created by guessever on 4/30/17.
//

#include "limit.h"
#include <stdio.h>
#include <sys/resource.h>

int setLimit(struct Limit *limit) {
    struct rlimit r;

    // set time limit
    r.rlim_cur = (limit->time_limit + 999) / 1000;
    r.rlim_max = r.rlim_cur + 1;
    if (setrlimit(RLIMIT_CPU, &r)) {
        puts("set RLIMIT_CPU error");
    };

    // set memory limit
    r.rlim_cur = limit->memory_limit * 1024; // convert `KB` to `B`
    r.rlim_max = r.rlim_cur + 1024;
    if (setrlimit(RLIMIT_DATA, &r)) {
        puts("set RLIMIT_DATA error");
    };
    if (setrlimit(RLIMIT_AS, &r)) {
        puts("set RLIMIT_AS error");
    };

    // set stack limit
    r.rlim_cur = limit->memory_limit * 1024;
    r.rlim_max = r.rlim_cur + 1024;
    if (setrlimit(RLIMIT_STACK, &r)) {
        puts("set RLIMIT_STACK error");
    };
}

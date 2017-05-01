//
// Created by guessever on 4/30/17.
//

#include "limit.h"
#include <stdio.h>
#include <sys/resource.h>
#include <zconf.h>
#include "grun.h"

#define SET_LIMIT(LIMIT, R) \
    if (setrlimit(LIMIT, R)) { \
        LOG("set " #LIMIT " error"); \
        return 1; \
    }

int set_limit(Limit &limit) {
    rlimit r;

    // set time limit
    r.rlim_cur = (limit.time_limit + 1500) / 1000;
    r.rlim_max = r.rlim_cur + 1;
    SET_LIMIT(RLIMIT_CPU, &r);

    // set memory limit
    // !!! REMEMBER TO CONVERT `KB` TO `B` HERE !!!
    r.rlim_cur = (limit.memory_limit + 1024) * 1024;
    r.rlim_max = r.rlim_cur + 1024 * 1024;
    SET_LIMIT(RLIMIT_DATA, &r);
    r.rlim_cur *= 2;
    r.rlim_max = r.rlim_cur + 1024 * 1024;
    SET_LIMIT(RLIMIT_AS, &r);

    // set stack limit
    // !!! REMEMBER TO CONVERT `KB` TO `B` HERE !!!
    r.rlim_cur = (limit.memory_limit + 1024) * 1024;
    r.rlim_max = r.rlim_cur + 1024 * 1024;
    SET_LIMIT(RLIMIT_STACK, &r);

    // set output limit
    // !!! REMEMBER TO CONVERT `KB` TO `B` HERE !!!
    r.rlim_cur = (limit.memory_limit + 1024) * 1024;
    r.rlim_max = r.rlim_cur + 1024 * 1024;
    SET_LIMIT(RLIMIT_FSIZE, &r);

    alarm(0);
    alarm(1);

    return 0;
}

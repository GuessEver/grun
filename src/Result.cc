//
// Created by guessever on 4/30/17.
//

#include <stdlib.h>
#include <signal.h>
#include "Limit.h"
#include "Grun.h"

/**
 * set time_used and memory_used
 * @param limit
 * @param usage
 * @return int
 */
int Result::set(rusage *usage) {
    this->time_used = usage->ru_utime.tv_sec * 1000
                        + usage->ru_utime.tv_usec / 1000 // cpu user time
                        + usage->ru_stime.tv_sec * 1000
                        + usage->ru_stime.tv_usec / 1000; // cpu system time
    this->memory_used = usage->ru_maxrss;
    return SUCCESS;
}

/**
 * set judge_result
 * @param limit
 * @param status
 * @return int
 */
int Result::set(Limit *limit, int code) {
    switch (code) {
        case SIGXFSZ:
            this->judge_result = OLE;
            break;

        case SIGSEGV:
            this->judge_result = MLE;
            break;

        case SIGALRM:
            alarm(0); // clear alarm clock first
        case SIGKILL:
        case SIGXCPU:
            this->judge_result = TLE;
            break;

        default:
            this->judge_result = RE;
            break;
    }
    return SUCCESS;
}

/**
 * fix judge result when done
 * @param limit
 * @return int
 */
int Result::fix(Limit *limit) {
    if (this->time_used > limit->time_limit) {
        this->judge_result = TLE;
    } else if (this->memory_used > limit->memory_limit) {
        this->judge_result = MLE;
    } else {
        this->judge_result = AC;
    }
    return SUCCESS;
 }

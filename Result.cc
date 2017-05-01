//
// Created by guessever on 4/30/17.
//

#include <stdlib.h>
#include <signal.h>
#include "Limit.h"
#include "Grun.h"

/**
 * Initialize data
 * @param limit
 * @param status
 * @param usage
 */
Result::Result(Limit *limit, int status, rusage *usage) {
    this->time_used = usage->ru_utime.tv_sec * 1000
                        + usage->ru_utime.tv_usec / 1000 // cpu user time
                        + usage->ru_stime.tv_sec * 1000
                        + usage->ru_stime.tv_usec / 1000; // cpu system time
    this->memory_used = usage->ru_maxrss;

    if (WIFSIGNALED(status)) {
        switch (WTERMSIG(status)) {
            case SIGXFSZ:
                this->judge_result = OLE;
                break;

            case SIGSEGV:
                this->judge_result = MLE;
                break;

            case SIGALRM:
            case SIGXCPU:
                this->judge_result = TLE;
                break;

            default:
                this->judge_result = RE;
                break;
        }
    } else {
        if (this->time_used > limit->time_limit) {
            this->judge_result = TLE;
        } else if (this->memory_used > limit->memory_limit) {
            this->judge_result = MLE;
        } else {
            this->judge_result = AC;
        }
    }
}


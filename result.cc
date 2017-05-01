//
// Created by guessever on 4/30/17.
//

#include <stdlib.h>
#include <signal.h>
#include "result.h"
#include "grun.h"

int set_result(Result &result, Limit &limit, int status, rusage &usage) {
    result.time_used = usage.ru_utime.tv_sec * 1000
                        + usage.ru_utime.tv_usec / 1000 // cpu user time
                        + usage.ru_stime.tv_sec * 1000
                        + usage.ru_stime.tv_usec / 1000; // cpu system time
    result.memory_used = usage.ru_maxrss;

    if (WIFSIGNALED(status)) {
        switch (WTERMSIG(status)) {
            case SIGXFSZ:
                result.judge_result = OLE;
                break;

            case SIGSEGV:
                result.judge_result = MLE;
                break;

            case SIGALRM:
            case SIGXCPU:
                result.judge_result = TLE;
                break;

            default:
                result.judge_result = RE;
                break;
        }
    } else {
        if (result.time_used > limit.time_limit) {
            result.judge_result = TLE;
        } else if (result.memory_used > limit.memory_limit) {
            result.judge_result = MLE;
        } else {
            result.judge_result = AC;
        }
    }

    return 0;
}

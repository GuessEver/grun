//
// Created by guessever on 4/30/17.
//

#include <stdbool.h>
#include "result.h"

bool setResult(struct Result *result, struct rusage *usage) {
    result->time_used = usage->ru_utime.tv_sec * 1000
                        + usage->ru_utime.tv_usec / 1000
                        + usage->ru_stime.tv_sec * 1000
                        + usage->ru_stime.tv_usec / 1000;
    result->memory_used = usage->ru_maxrss;
}

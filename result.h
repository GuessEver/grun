//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_RESULT_H
#define GRUN_RESULT_H

#include <sys/resource.h>

enum JUDGE_RESULT {
    Pending = 1,
    Judging,
    AC,
    PE,
    WA,
    OLE,
    TLE,
    MLE,
    CE,
    RE,
    SE,
};

struct Result {
    long time_used; // in MS
    long memory_used; // in KB
    enum JUDGE_RESULT judge_result;
};

bool setResult(struct Result *result, struct rusage *usage);

#endif //GRUN_RESULT_H

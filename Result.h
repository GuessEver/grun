//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_RESULT_H
#define GRUN_RESULT_H

#include <sys/resource.h>
#include "Limit.h"

enum JUDGE_RESULT {
    Pending = 1,    //  1 Pending
    Judging,        //  2 Judging
    AC,             //  3 Accepted
    PE,             //  4 Presentation Error
    WA,             //  5 Wrong Answer
    OLE,            //  6 Output Limit Exceeded
    TLE,            //  7 Time Limit Exceeded
    MLE,            //  8 Memory Limit Exceeded
    CE,             //  9 Compilation Error
    RE,             // 10 Runtime Error
    SE,             // 11 System Error
};

struct Result {
private:
public:
    long time_used; // in MS
    long memory_used; // in KB
    enum JUDGE_RESULT judge_result;
    int set(Limit *limit, rusage *usage);
    int set(Limit *limit, int status);
    int fix(Limit *limit);
};


#endif //GRUN_RESULT_H

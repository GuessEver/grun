//
// Created by guessever on 5/1/17.
//

#ifndef GRUN_RUNNER_H
#define GRUN_RUNNER_H

#include <unistd.h>
#include "Limit.h"
#include "Result.h"
#include "Code.h"
#include "Access.h"

class Runner {
private:
    int trace(pid_t pid);
public:
    Limit *limit;
    Result *result;
    Access *access;
    char info[1024] = "";
    Runner(Code *code, unsigned time_limit, unsigned memory_limit, unsigned output_limit);
    int run(Code *code, const char *input);
};


#endif //GRUN_RUNNER_H

//
// Created by guessever on 5/1/17.
//

#ifndef GRUN_RUNNER_H
#define GRUN_RUNNER_H

#include <vector>
#include <unistd.h>
#include "Limit.h"
#include "Result.h"
#include "Code.h"

class Runner {
private:
    int trace(pid_t pid);
public:
    Limit *limit;
    Result *result;
    Runner(unsigned time_limit, unsigned memory_limit, unsigned output_limit);
    int run(Code *code, const char *input);
};


#endif //GRUN_RUNNER_H

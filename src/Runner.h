//
// Created by guessever on 5/1/17.
//

#ifndef GRUN_RUNNER_H
#define GRUN_RUNNER_H

#include "Limit.h"
#include "Result.h"
#include <unistd.h>

class Runner {
private:
    int trace(pid_t pid);
public:
    Limit *limit;
    Result *result;
    char **args;
    int run();
};


#endif //GRUN_RUNNER_H

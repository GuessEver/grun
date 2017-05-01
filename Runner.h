//
// Created by guessever on 5/1/17.
//

#ifndef GRUN_RUNNER_H
#define GRUN_RUNNER_H

#include "Limit.h"
#include "Result.h"

class Runner {
private:
public:
    Limit *limit;
    Result *result;
    char **args;
    int run();
};


#endif //GRUN_RUNNER_H

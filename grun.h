//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_GRUN_H
#define GRUN_GRUN_H

#include <stdbool.h>
#include "limit.h"
#include "result.h"

struct Runner {
    struct Limit limit;
    struct Result result;
    char **args;
};

bool run(struct Runner *program);

#endif //GRUN_GRUN_H

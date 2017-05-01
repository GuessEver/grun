//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_GRUN_H
#define GRUN_GRUN_H

#include "limit.h"
#include "result.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE
#define LOG(FORMAT, ...) fprintf(stderr, "[LOG] " FORMAT "\n", ##__VA_ARGS__)
#else
#define LOG(FORMAT, ...) {}
#endif

struct Runner {
    struct Limit limit;
    struct Result result;
    char **args;
};

int run(Runner &program);

#endif //GRUN_GRUN_H

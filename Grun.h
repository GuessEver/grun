//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_GRUN_H
#define GRUN_GRUN_H

#include "Compiler.h"
#include "Runner.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE
#define LOG(FORMAT, ...) fprintf(stderr, "[LOG] " FORMAT "\n", ##__VA_ARGS__)
#else
#define LOG(FORMAT, ...) {}
#endif

class Grun {
private:
public:
    Compiler *compiler;
    Runner *runner;
};


#endif //GRUN_GRUN_H

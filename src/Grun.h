//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_GRUN_H
#define GRUN_GRUN_H

#include <iostream>
#include "Compiler.h"
#include "Runner.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE
#define LOG(FORMAT, ...) fprintf(stderr, "[LOG] " FORMAT "\n", ##__VA_ARGS__)
#define LOG2(VAR) std::cerr << "[LOG] " << #VAR << " " << VAR << std::endl
#else
#define LOG(FORMAT, ...) {}
#define LOG2(VAR) {}
#endif

#define SUCCESS 0
#define ERROR 1

class Grun {
private:
public:
    Compiler *compiler;
    Runner *runner;
};


#endif //GRUN_GRUN_H

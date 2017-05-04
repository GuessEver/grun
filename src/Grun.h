//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_GRUN_H
#define GRUN_GRUN_H

#include <stdio.h>
#include <iostream>
#include "Code.h"
#include "Compiler.h"
#include "Runner.h"
#include "Judger.h"

//#define DEBUG_MODE

#define INFO(FORMAT, ...) fprintf(stderr, "[INFO] " FORMAT "\n", ##__VA_ARGS__)

#ifdef DEBUG_MODE
#define LOG(FORMAT, ...) fprintf(stderr, "[LOG] " FORMAT "\n", ##__VA_ARGS__)
#define LOG2(VAR) std::cerr << "[LOG] " << #VAR << " " << VAR << std::endl
#else
#define LOG(FORMAT, ...) {}
#define LOG2(VAR) {}
#endif

#define SUCCESS 0
#define ERROR -1

int execute_cmd(const char *fmt, ...);

class Grun {
private:
    const char * work_dir;
public:
    Code *code;
    Compiler *compiler;
    Runner *runner;
    Judger *judger;
    Result *result;
    Grun(const char *path, unsigned time_limit, unsigned memory_limit, unsigned output_limit);
    int prepare(const char *work_dir);
    int compile();
    int run(const char *input, const char *output);
    int clear();
};


#endif //GRUN_GRUN_H

//
// Created by guessever on 5/1/17.
//

#ifndef GRUN_COMPILER_H
#define GRUN_COMPILER_H

#include "Code.h"
#include "Limit.h"
#include "Result.h"

class Compiler {
private:
public:
    Limit *limit;
    Result *result;
    const char *info;
    Compiler(unsigned time_limit, unsigned memory_limit, unsigned output_limit);
    int compile(Code *code);
};


#endif //GRUN_COMPILER_H

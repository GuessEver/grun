//
// Created by guessever on 5/4/17.
//

#ifndef GRUN_ACCESS_H
#define GRUN_ACCESS_H

#include <sys/syscall.h>
#include <sys/user.h>
#include "Code.h"

#define MAX_CALL_SIZE 512

class Access {
private:
public:
    int call[MAX_CALL_SIZE];
    Access(Code *code);
    int check(user_regs_struct *regs);
};


#endif //GRUN_ACCESS_H

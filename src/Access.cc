//
// Created by guessever on 5/4/17.
//

#include "Access.h"
#include "Grun.h"

#ifdef __i386
#include "okcalls32.h"
#define REG_SYSCALL orig_eax
#else
#include "okcalls64.h"
#define REG_SYSCALL orig_rax
#endif

Access::Access(Code *code) {
    unsigned *okcall = OKCALL_C;
    switch (code->language) {
        case Pascal:
            okcall = OKCALL_PASCAL;
            break;
        case C:
        case CC:
            okcall = OKCALL_C;
            break;
        case Java:
            okcall = OKCALL_JAVA;
            break;
        case Python:
            okcall = OKCALL_PYTHON;
            break;
        case Lua:
            okcall = OKCALL_LUA;
            break;
    }
    for (int i = 0; i < MAX_CALL_SIZE; i++) {
        this->call[i] = ERROR;
    }
    for (int i = 0; okcall[i] < 500; i++) {
        this->call[okcall[i]] = SUCCESS;
    }
}

int Access::check(user_regs_struct *regs) {
    return this->call[regs->REG_SYSCALL];
}

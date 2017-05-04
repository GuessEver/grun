//
// Created by guessever on 5/1/17.
//

#include "Compiler.h"
#include <stdio.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include "Grun.h"

Compiler::Compiler(unsigned time_limit, unsigned memory_limit, unsigned output_limit) {
    this->limit = new Limit(time_limit, memory_limit, output_limit);
}

int Compiler::compile(Code *code) {
    pid_t pid = fork();
    if (pid < 0) {
    } else if (pid == 0) {
        // set resources limits
        if (this->limit->set()) {
            LOG("set_limit error");
            return ERROR;
        }

        // execute
        switch (code->language) {
            case Pascal:
                execl("/usr/bin/fpc", "/usr/bin/fpc", code->filename, NULL);
            case C:
                execl("/usr/bin/gcc", "/usr/bin/gcc", code->filename, "-o", "Main", NULL);
            case CC:
                execl("/usr/bin/g++", "/usr/bin/g++", code->filename, "-o", "Main",  NULL);
                break;
            case Java:
                execl("/opt/jdk1.8.0_77/bin/javac", "/opt/jdk1.8.0_77/bin/javac", code->filename, NULL);
                break;
            case Python:
            case Lua:
                break;
            default:
                break;
        }
        _exit(0);
    } else if (pid > 0) {
        int status = -1;
        waitpid(pid, &status, 0);
        if (status != SUCCESS) {
            this->result->judge_result = CE;
            return ERROR;
        }
    }
    return SUCCESS;
}

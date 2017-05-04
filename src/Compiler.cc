//
// Created by guessever on 5/1/17.
//

#include "Compiler.h"
#include <stdio.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include "Grun.h"

/**
 * initialize data
 * @param time_limit
 * @param memory_limit
 * @param output_limit
 */
Compiler::Compiler(unsigned time_limit, unsigned memory_limit, unsigned output_limit) {
    this->limit = new Limit(time_limit, memory_limit, output_limit);
}

/**
 * compile the program
 * @param code
 * @return SUCCESS | ERROR
 */
int Compiler::compile(Code *code) {
    pid_t pid = fork();
    if (pid < 0) {
    } else if (pid == 0) {
        // set resources limits
        if (this->limit->set()) {
            LOG("set_limit error");
            return ERROR;
        }

        freopen("compile.out", "w", stderr);
        freopen("compile.out", "a+", stdout);
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
        }
        _exit(0);
    } else if (pid > 0) {
        int status = -1;
        waitpid(pid, &status, 0);

        FILE *error_file = fopen("compile.out", "r");
        int cnt = 0;
        while(cnt < 1000 && fscanf(error_file, "%c", this->info + cnt) != EOF) cnt++;

        if (status != SUCCESS) {
            this->result->judge_result = CE;
            return ERROR;
        }
    }
    return SUCCESS;
}

//
// Created by guessever on 5/1/17.
//

#include "Runner.h"
#include <stdio.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include "Grun.h"

/**
 * Run program
 * @return int
 */
int Runner::run() {
    pid_t pid = fork();
    if (pid < 0) {
    } else if (pid == 0) {
        // set resources limits
        if (this->limit->set()) {
            LOG("set_limit error");
            return ERROR;
        }

        // redefine input and output
//        freopen("data.in", "r", stdin);
//        freopen("data.out", "w", stdout);

        // wait the parent process to trace
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            LOG("ptrace TRACEME error");
            return ERROR;
        }

        // execute
        execv(this->args[0], this->args);
        _exit(0);
    } else if (pid > 0) {
        // trace the child process
        this->result = new Result();
        if (this->trace(pid)) {
            LOG("trace monitor error");
            return ERROR;
        }
    }
    return SUCCESS;
}

/**
 * Trace program
 * @param pid
 * @return int
 */
int Runner::trace(pid_t pid) {
    int status = -1;
    rusage usage;
    while(1) {
        if (wait4(pid, &status, 0, &usage) == -1) {
            LOG("wait4 error");
            return ERROR;
        }
        if (WIFEXITED(status)) { // exited normally
            break;
        }
        if (WEXITSTATUS(status) != SIGTRAP) {
            LOG("WEXITSTATUS | %d", WEXITSTATUS(status));
            ptrace(PTRACE_KILL, pid, NULL, NULL);
            this->result->set(this->limit, WEXITSTATUS(status));
            this->result->set(this->limit, &usage);
            return ERROR;
        }
        if (WIFSIGNALED(status)) {
            LOG("WIFSIGNALED WTERMSIG | %d", WTERMSIG(status));
            ptrace(PTRACE_KILL, pid, NULL, NULL);
            this->result->set(this->limit, WTERMSIG(status));
            this->result->set(this->limit, &usage);
            return ERROR;
        }
//        user_regs_struct regs;
//        if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1) {
//            LOG("PTRACE_GETREGS error");
//        }
//        LOG2(regs.cs);
//        LOG2(regs.ds);

        // continue but stop when next system call
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
    }
    this->result->set(this->limit, &usage);
    this->result->fix(this->limit);
    return SUCCESS;
}

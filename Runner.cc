//
// Created by guessever on 5/1/17.
//

#include "Runner.h"
#include <stdio.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include "Grun.h"

/**
 * Run program
 * @return int 0 - success
 *             1 - error
 */
int Runner::run() {
    pid_t pid = fork();
    if (pid < 0) {
    } else if (pid == 0) {
        LOG("starting...");

        // set resources limits
        if (this->limit->set()) {
            LOG("set_limit error");
            return 1;
        }

        // redefine input and output
//        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);

        // wait the parent process to trace
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            LOG("ptrace TRACEME error");
        }

        // execute
        execv(this->args[0], this->args);
        _exit(0);
    } else if (pid > 0) {
        // trace the child process
        this->result = new Result();
        if (this->trace(pid)) {
            LOG("trace monitor error");
            return 1;
        }
    }
    return 0;
}

/**
 * Trace program
 * @param pid
 * @return int 0 - success
 *             1 - error
 */
int Runner::trace(pid_t pid) {
    int status = -1;
    rusage usage;
    while(1) {
        if (wait4(pid, &status, 0, &usage) == -1) {
            LOG("wait4 error");
            return 1;
        }
        if (WIFEXITED(status)) { // exited normally
            break;
        }
        if (WEXITSTATUS(status) != SIGTRAP) {
            LOG("WEXITSTATUS | %d", WEXITSTATUS(status));
            ptrace(PTRACE_KILL, pid, NULL, NULL);
            this->result->set(this->limit, WEXITSTATUS(status));
            this->result->set(this->limit, &usage);
            return 0;
        }
        if (WIFSIGNALED(status)) {
            LOG("WIFSIGNALED WTERMSIG | %d", WTERMSIG(status));
            ptrace(PTRACE_KILL, pid, NULL, NULL);
            this->result->set(this->limit, WTERMSIG(status));
            this->result->set(this->limit, &usage);
            return 0;
        }
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
    }
    this->result->set(this->limit, &usage);
    this->result->fix(this->limit);
    return 0;
}

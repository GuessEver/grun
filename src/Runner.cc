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
 * init args with language
 * @param time_limit
 * @param memory_limit
 * @param output_limit
 */
Runner::Runner(Code *code, unsigned time_limit, unsigned memory_limit, unsigned output_limit) {
    this->access = new Access(code);
    this->limit = new Limit(time_limit, memory_limit, output_limit);
}

/**
 * Run program
 * @param code
 * @param input
 * @param output
 * @return int
 */
int Runner::run(Code *code, const char *input) {
    pid_t pid = fork();
    if (pid < 0) {
    } else if (pid == 0) {
        // set resources limits
        if (this->limit->set()) {
            LOG("set_limit error");
            return ERROR;
        }

        // redefine input and output
        freopen(input, "r", stdin);
        freopen("data.out", "w", stdout);

        // wait the parent process to trace
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            LOG("ptrace TRACEME error");
            return ERROR;
        }

        // execute
        switch (code->language) {
            case Pascal:
            case C:
            case CC:
                execl("./Main", "./Main", NULL);
                break;
            case Java:
                execl("/opt/jdk1.8.0_77/bin/java", "/opt/jdk1.8.0_77/bin/java", code->filename2, NULL);
                break;
            case Python:
                execl("/usr/share/python", "/usr/share/python", code->filename, NULL);
                break;
            case Lua:
                execl("/usr/local/bin/lua", "/usr/local/bin/lua", code->filename, NULL);
                break;
        }
        _exit(0);
    } else if (pid > 0) {
        // trace the child process
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
            this->result->set(&usage);
            return ERROR;
        }
        if (WIFSIGNALED(status)) {
            LOG("WIFSIGNALED WTERMSIG | %d", WTERMSIG(status));
            ptrace(PTRACE_KILL, pid, NULL, NULL);
            this->result->set(this->limit, WTERMSIG(status));
            this->result->set(&usage);
            return ERROR;
        }

        // check system call
        user_regs_struct regs;
        if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1) {
            LOG("PTRACE_GETREGS error");
        }
        if (this->access->check(&regs) == ERROR) {
            sprintf(this->info, "!!! ERROR !!! calling sys[%lld] restricted", regs.orig_rax);
            LOG2(regs.orig_rax);
            ptrace(PTRACE_KILL, pid, NULL, NULL);
            this->result->judge_result = RF;
            this->result->set(&usage);
            return SUCCESS;
        }

        // continue but stop when next system call
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
    }
    this->result->set(&usage);
    this->result->fix(this->limit);
    return SUCCESS;
}


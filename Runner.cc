//
// Created by guessever on 5/1/17.
//

#include "Runner.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
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
        if (this->limit->set()) {
            LOG("set_limit error");
            return 1;
        }
//        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        execv(this->args[0], this->args);
        _exit(0);
    } else if (pid > 0) {
        int status = -1;
        struct rusage usage;
        wait4(pid, &status, 0, &usage);
        this->result = new Result(this->limit, status, &usage);
    }
    return 0;
}

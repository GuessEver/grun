//
// Created by guessever on 4/30/17.
//

#include "grun.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int run(Runner &program) {
    pid_t pid = fork();
    if (pid < 0) {
    } else if (pid == 0) {
        LOG("starting...");
        if (set_limit(program.limit)) {
            LOG("set_limit error");
            return 1;
        }
//        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        execv(program.args[0], program.args);
        _exit(0);
    } else if (pid > 0) {
        int status = -1;
        struct rusage usage;
        wait4(pid, &status, 0, &usage);
        if (set_result(program.result, program.limit, status, usage)) {
            LOG("set_result error");
            return 1;
        }
    }
    return 0;
}

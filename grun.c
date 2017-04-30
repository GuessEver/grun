//
// Created by guessever on 4/30/17.
//

#include "grun.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

bool run(struct Runner *program) {
    pid_t pid = fork();
    if (pid < 0) {
        puts("fork error");
    } else if (pid == 0) {
        setLimit(&program->limit);
        execvp(program->args[0], program->args);
        _exit(0);
    } else if (pid > 0) {
        int status = -1;
        struct rusage usage;
        wait4(pid, &status, 0, &usage);
        setResult(&program->result, &usage);
    }
}

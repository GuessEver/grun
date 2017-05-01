#include <stdio.h>
#include "grun.h"

int main() {
    LOG("You ARE running in DEBUG MOD !");
    struct Runner program;
    program.limit.output_limit = 100;
    program.limit.memory_limit = 1150;
    program.limit.time_limit = 1000;
    char* argv[] = {(char *) "/home/guessever/test/c1", NULL};
    program.args = (char **) argv;
    if (run(program)) {
        LOG("run error");
    }

    LOG("time = %ld MS", program.result.time_used);
    LOG("memory = %ld KB", program.result.memory_used);
    LOG("judge_result = %d", program.result.judge_result);
    return 0;
}

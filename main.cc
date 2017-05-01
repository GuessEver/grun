#include <stdio.h>
#include "Grun.h"

int main() {
    LOG("You ARE running in DEBUG MOD !");
    Grun *program = new Grun();
    program->compiler = new Compiler();
    program->runner = new Runner();
    program->runner->limit = new Limit(100, 1150, 1000);
    char* argv[] = {(char *) "/home/guessever/test/c1", NULL};
    program->runner->args = (char **) argv;
    if (program->runner->run()) {
        LOG("run error");
    }

    LOG("time = %ld MS", program->runner->result->time_used);
    LOG("memory = %ld KB", program->runner->result->memory_used);
    LOG("judge_result = %d", program->runner->result->judge_result);
    return 0;
}

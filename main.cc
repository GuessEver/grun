#include <stdio.h>
#include "Grun.h"

int main() {
    LOG("You ARE running in DEBUG MOD !");
    Grun *program = new Grun();
    program->compiler = new Compiler();
    program->runner = new Runner();
    program->runner->limit = new Limit(1000, 256 * 1024, 100);
    char* argv[] = {(char *) "/home/guessever/test/c2", NULL};
    program->runner->args = (char **) argv;
    if (program->runner->run()) {
        LOG("run error");
    }

    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    return 0;
}

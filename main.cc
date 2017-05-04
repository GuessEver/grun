
#include "src/Grun.h"

int main() {
    Grun *program = new Grun(
            "/home/guessever/test/ab.cpp", // source code file
            1000, // time limit (MS)
            256 * 1024, // memory limit (KB)
            512 * 1024 // output limit (KB)
    );
    program->prepare();
    program->compile();
    char *input = new char [255];
    char *output = new char [255];
    for (int i = 0; i < 5; i++) {
        sprintf(input, "/home/guessever/abtest/%03d.in", i);
        sprintf(output, "/home/guessever/abtest/%03d.out", i);
        if (i <= 2) {
            sprintf(output, "/home/guessever/abtest/%03d.out", i);
        } else {
            sprintf(output, "/home/guessever/abtest/%03d.ans", i);
        }
        program->run(input, output);
        if (program->runner->result) {
            LOG("[result] time = %ld MS", program->runner->result->time_used);
            LOG("[result] memory = %ld KB", program->runner->result->memory_used);
            LOG("[result] judge_result = %d", program->runner->result->judge_result);
        }
    }
    return 0;
}


#include "src/Grun.h"

int main() {
    Grun *program = new Grun(
            "/home/guessever/test/tester.cpp", // source code file
            "/home/guessever/abtest", // data directory
            1000, // time limit (MS)
            256 * 1024, // memory limit (KB)
            512 * 1024 // output limit (KB)
    );
    program->prepare();
    program->start();
    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    return 0;
}

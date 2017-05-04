
#include "src/Grun.h"

int main() {
    Grun * program = new Grun(
            "/home/guessever/test/ab.cpp", // source code file
            1000, // time limit (MS)
            256 * 1024, // memory limit (KB)
            512 * 1024 // output limit (KB)
    );
    program->prepare();
    program->compile();
    program->run("/home/guessever/abtest/000.in", "/home/guessever/abtest/000.out");
    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    program->run("/home/guessever/abtest/001.in", "/home/guessever/abtest/001.out");
    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    program->run("/home/guessever/abtest/002.in", "/home/guessever/abtest/002.out");
    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    program->run("/home/guessever/abtest/003.in", "/home/guessever/abtest/003.ans");
    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    program->run("/home/guessever/abtest/004.in", "/home/guessever/abtest/004.ans");
    if (program->runner->result) {
        LOG("[result] time = %ld MS", program->runner->result->time_used);
        LOG("[result] memory = %ld KB", program->runner->result->memory_used);
        LOG("[result] judge_result = %d", program->runner->result->judge_result);
    }
    return 0;
}

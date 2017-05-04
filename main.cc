
#include "src/Grun.h"

const char *JUDGE_RESULT_ZH[] = {
        "",
        "Pending",
        "Judging",
        "Accepted",
        "Presentation Error",
        "Wrong Answer",
        "Output Limit Exceeded",
        "Time Limit Exceeded",
        "Memory Limit Exceeded",
        "Compilation Error",
        "Runtime Error",
        "Restricted Function",
        "System Error",
};

int main() {
    Grun *program = new Grun(
            "/home/guessever/grun/tests/RFfreopen.cpp", // source code file
            1000, // time limit (MS)
            256 * 1024, // memory limit (KB)
            512 * 1024 // output limit (KB)
    );
    program->prepare("/home/guessever/grun/judge");
    if (program->compile() == SUCCESS) {
        program->run("/home/guessever/grun/tests/000.in", "/home/guessever/grun/tests/000.out");
    }
    INFO("[compile] %s", program->compiler->info);
    INFO("[run] %s", program->runner->info);
    INFO("[result] (%d) %s", program->result->judge_result, JUDGE_RESULT_ZH[program->result->judge_result]);
    INFO("[result] time = %ld MS", program->result->time_used);
    INFO("[result] memory = %ld KB", program->result->memory_used);
    return 0;
}

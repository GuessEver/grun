
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
            "/home/guessever/test/ab.cpp", // source code file
            1000, // time limit (MS)
            256 * 1024, // memory limit (KB)
            512 * 1024 // output limit (KB)
    );
    program->prepare("/home/guessever/grun/judge");
    if (program->compile()) {
        LOG("[result] judge_result = %d", program->result->judge_result);
        return 0;
    }
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
        INFO("[result] (%d) %s", program->result->judge_result, JUDGE_RESULT_ZH[program->result->judge_result]);
        INFO("[result] time = %ld MS", program->result->time_used);
        INFO("[result] memory = %ld KB", program->result->memory_used);
    }
    return 0;
}

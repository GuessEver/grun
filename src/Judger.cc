//
// Created by guessever on 5/4/17.
//

#include "Judger.h"
#include "Grun.h"

/**
 * judge user output with answer in strict mode
 * @param answer
 * @return JUDGE_RESULT
 */
JUDGE_RESULT Judger::strict(const char *answer) {
    if (execute_cmd("diff %s %s > diff.out", answer, "data.out") == SUCCESS) {
        return AC;
    } else if (execute_cmd("diff -wb %s %s > diff.out", answer, "data.out") == SUCCESS) {
        return PE;
    } else {
        return WA;
    }
}

//
// Created by guessever on 5/4/17.
//

#include "Judger.h"
#include "Grun.h"

JUDGE_RESULT Judger::strict(const char *answer) {
    if (execute_cmd("diff %s %s", answer, "data.out") == SUCCESS) {
        return AC;
    } else if (execute_cmd("diff -wb %s %s", answer, "data.out") == SUCCESS) {
        return PE;
    } else {
        return WA;
    }
}

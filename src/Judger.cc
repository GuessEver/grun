//
// Created by guessever on 5/4/17.
//

#include "Judger.h"
#include "Grun.h"

JUDGE_RESULT Judger::strict(const char *answer) {
    int ret = execute_cmd("diff %s %s", answer, "data.out");
    LOG2(ret);
    return AC;
}

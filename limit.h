//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_LIMIT_H
#define GRUN_LIMIT_H

struct Limit {
    unsigned int time_limit; // in MS
    unsigned int memory_limit; // in KB
    unsigned int output_limit; // in KB
};

int set_limit(Limit &limit);

#endif //GRUN_LIMIT_H

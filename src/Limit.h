//
// Created by guessever on 4/30/17.
//

#ifndef GRUN_LIMIT_H
#define GRUN_LIMIT_H

class Limit {
private:
public:
    unsigned time_limit; // in MS
    unsigned memory_limit; // in KB
    unsigned output_limit; // in KB
    Limit(unsigned t, unsigned m, unsigned o);
    int set();
};


#endif //GRUN_LIMIT_H

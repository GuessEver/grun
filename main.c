#include <stdio.h>
#include "grun.h"

int main() {
    struct Runner program;
    program.limit.memory_limit = 390 * 1024;
    program.limit.time_limit = 3300;
    char* argv[] = {"./tester", "tester", (char *) 0};
    program.args = (char **) argv;
    run(&program);
    printf("time = %ld MS\n", program.result.time_used);
    printf("memory = %ld KB\n", program.result.memory_used);
    return 0;
}

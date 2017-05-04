//
// Created by guessever on 4/30/17.
//

#include <sys/stat.h>
#include <sys/wait.h>
#include <cstdlib>
#include <stdarg.h>
#include "Grun.h"

int execute_cmd(const char * fmt, ...) {
    char cmd[512];

    int ret = 0;
    va_list ap;

    va_start(ap, fmt);
    vsprintf(cmd, fmt, ap);
    ret = system(cmd);
    va_end(ap);
    return ret;
}

Grun::Grun(const char *path, unsigned time_limit, unsigned memory_limit, unsigned output_limit) {
    LOG("You ARE running in DEBUG MOD !");
    this->code = new Code(path);
    this->compiler = new Compiler(10000, 256 * 1024, 512 * 1024);
    this->runner = new Runner(time_limit, memory_limit, output_limit);
}

int Grun::prepare() {
    // change to work directory
    execute_cmd("/bin/rm -rf %s", "work");
    if (mkdir("work", 0755)) {
        LOG("mkdir [work] error");
        return ERROR;
    }
    if (chdir("work")) {
        LOG("chdir [work] error");
        return ERROR;
    }
    execute_cmd("/bin/cp %s %s", (char *)this->code->path.c_str(), (char *)this->code->filename.c_str());
}

int Grun::compile() {
    if (this->compiler->compile(this->code) == ERROR) {
        LOG("compile error");
        return ERROR;
    }
    return 0;
}

int Grun::run(const char *input, const char *output) {
    if (this->runner->run(this->code, input, output) == ERROR) {
        LOG("run error");
        return ERROR;
    }
    if (this->runner->result->judge_result == AC) {
        this->judger = new Judger();
        this->runner->result->judge_result = this->judger->strict(output);
    }
    return 0;
}



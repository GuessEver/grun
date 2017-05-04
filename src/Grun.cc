//
// Created by guessever on 4/30/17.
//

#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Grun.h"

/**
 * execute command use system call
 * @param fmt
 * @param ...
 * @return status code
 */
int execute_cmd(const char *fmt, ...) {
    char cmd[512];

    int ret = 0;
    va_list ap;

    va_start(ap, fmt);
    vsprintf(cmd, fmt, ap);
    ret = system(cmd);
    va_end(ap);
    return ret;
}

/**
 * initialize data
 * @param path
 * @param time_limit
 * @param memory_limit
 * @param output_limit
 */
Grun::Grun(const char *path, unsigned time_limit, unsigned memory_limit, unsigned output_limit) {
    LOG("You ARE running in DEBUG MOD !");
    this->code = new Code(path);
    this->compiler = new Compiler(10000, 256 * 1024, 512 * 1024);
    this->runner = new Runner(this->code, time_limit, memory_limit, output_limit);
    this->result = new Result();
    this->compiler->result = this->result;
    this->runner->result = this->result;
}

/**
 * prepare work directory
 * @param work_dir
 * @return SUCCESS | ERROR
 */
int Grun::prepare(const char *work_dir) {
    this->work_dir = work_dir;
    if (this->clear()) {
        return ERROR;
    }
    if (mkdir(work_dir, 0755)) {
        LOG("mkdir [%s] error", this->work_dir);
        return ERROR;
    }
    if (chdir(this->work_dir)) {
        LOG("chdir [%s] error", this->work_dir);
        return ERROR;
    }
    if (execute_cmd("/bin/cp %s %s", this->code->path, this->code->filename) != SUCCESS) {
        LOG("copy code error");
        return ERROR;
    }
    return SUCCESS;
}

/**
 * call compiler
 * @return SUCCESS | ERROR
 */
int Grun::compile() {
    if (this->compiler->compile(this->code) == ERROR) {
        LOG("compile error");
        return ERROR;
    }
    return SUCCESS;
}

/**
 * call runner and judger
 * @param input
 * @param output
 * @return SUCCESS | ERROR
 */
int Grun::run(const char *input, const char *output) {
    if (this->runner->run(this->code, input) == ERROR) {
        LOG("run error");
        return ERROR;
    }
    if (this->runner->result->judge_result == AC) {
        this->judger = new Judger();
        this->runner->result->judge_result = this->judger->strict(output);
    }
    return SUCCESS;
}

/**
 * clear work directory
 * @return SUCCESS | ERROR
 */
int Grun::clear() {
    chdir(this->work_dir);
    if (execute_cmd("/bin/rm -rf %s", this->work_dir) != SUCCESS) {
        LOG("clear work directory error");
        return ERROR;
    }
    return SUCCESS;
}



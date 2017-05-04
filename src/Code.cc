//
// Created by guessever on 5/3/17.
//

#include <string.h>
#include "Code.h"
#include "Grun.h"

const char *getExtension(const char *filename) {
    long len = strlen(filename) - 1;
    for (long i = 0; filename[i]; i++) {
        if (filename[i] == '.') {
            len = i;
        }
    }
    return filename + len + 1;
}

Code::Code(const char *path) {
    this->path = path;

    const char *ext = getExtension(this->path);
    if (!strcmp(ext, "pas")) {
        this->language = Pascal;
        this->extension = "pas";
    } else if (!strcmp(ext, "c")) {
        this->language = C;
        this->extension = "c";
    } else if (!strcmp(ext, "cc") || !strcmp(ext, "cxx") || !strcmp(ext, "cpp")) {
        this->language = CC;
        this->extension = "cc";
    } else if (!strcmp(ext, "java")) {
        this->language = Java;
        this->extension = "java";
    } else if (!strcmp(ext, "py")) {
        this->language = Python;
        this->extension = "py";
    } else if (!strcmp(ext, "lua")) {
        this->language = Lua;
        this->extension = "lua";
    }
    this->filename2 = "Main";
    char *tmp = new char[255];
    sprintf(tmp, "%s.%s", this->filename2, this->extension);
    this->filename = tmp;
}

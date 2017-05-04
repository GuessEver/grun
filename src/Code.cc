//
// Created by guessever on 5/3/17.
//

#include <algorithm>
#include "Code.h"
#include "Grun.h"

std::string getExtension(std::string &filename) {
    std::string ext = "";
    for (std::string::iterator it = filename.end() - 1; it != filename.begin(); it--) {
        if (*it == '.') {
            break;
        }
        ext = (*it) + ext;
    }
    return ext;
}

Code::Code(const char *path) {
    this->path = std::string(path);

    std::string ext = getExtension(this->path);
    if (ext == "pas") {
        this->language = Pascal;
        this->extension = "pas";
    } else if (ext == "c") {
        this->language = C;
        this->extension = "c";
    } else if (ext == "cc" || ext == "cxx" || ext == "cpp") {
        this->language = CC;
        this->extension = "cc";
    } else if (ext == "java") {
        this->language = Java;
        this->extension = "java";
    } else if (ext == "py") {
        this->language = Python;
        this->extension = "py";
    } else if (ext == "lua") {
        this->language = Lua;
        this->extension = "lua";
    }
    this->filename2 = "Main";
    this->filename = this->filename2 + "." + this->extension;
}

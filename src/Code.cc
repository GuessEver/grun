//
// Created by guessever on 5/3/17.
//

#include <dirent.h>
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

Code::Code(std::string path, std::string data_dir) {
    this->path = path;

    std::string ext = getExtension(path);
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
    this->filename = "Main." + this->extension;

    this->data_dir = data_dir;
    this->data_input.clear();
    this->data_output.clear();
    DIR *dir = opendir((char *)data_dir.c_str());
    dirent *ptr;
    while(ptr = readdir(dir)) {
        if (ptr->d_name[0] == '.') {
            continue;
        }
        std::string filename = std::string(ptr->d_name);
        std::string ext = getExtension(filename);
        if (ext == "in" || ext == "input") {
            this->data_input.push_back(filename);
        } else if (ext == "ou" || ext == "out" || ext == "output" || ext == "ans" || ext == "answer") {
            this->data_output.push_back(filename);
        }
    }
    std::sort(this->data_input.begin(), this->data_input.end());
    std::sort(this->data_output.begin(), this->data_output.end());
    // remove the extra data
    while (this->data_input.size() > this->data_output.size()) {
        this->data_input.pop_back();
    }
}

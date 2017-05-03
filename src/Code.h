//
// Created by guessever on 5/3/17.
//

#ifndef GRUN_LANGUAGE_H
#define GRUN_LANGUAGE_H

#include <string>
#include <vector>

enum Language {
    Pascal = 1,
    C,
    CC,
    Java,
    Python,
    Lua,
};

class Code {
private:
public:
    std::string path;
    Language language;
    std::string extension;
    std::string filename;
    std::string data_dir;
    std::vector<std::string> data_input, data_output;
    Code(std::string path, std::string data_dir);
};


#endif //GRUN_LANGUAGE_H

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
    std::string filename2;
    Code(const char *path);
};


#endif //GRUN_LANGUAGE_H

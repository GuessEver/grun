//
// Created by guessever on 5/3/17.
//

#ifndef GRUN_LANGUAGE_H
#define GRUN_LANGUAGE_H

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
    const char *path;
    Language language;
    const char *extension;
    const char *filename;
    const char *filename2;
    Code(const char *path);
};


#endif //GRUN_LANGUAGE_H

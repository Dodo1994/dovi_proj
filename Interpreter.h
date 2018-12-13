
#ifndef INTERPRETER_H
#define INTERPRETER_H

using namespace std;

#include <string>
#include <list>

class interpreter {

public:
    list<string> lexer(string input);
    void parser();

private:
    bool isSpace(char c);
};


#endif

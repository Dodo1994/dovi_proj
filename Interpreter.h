
#ifndef INTERPRETER_H
#define INTERPRETER_H

using namespace std;

#include <string>
#include <list>
#include <map>
#include "Expression.h"

class interpreter {
    map<string, Expression> vars_map;

public:
    list<string> lexer(string input);
    void parser();

private:
    bool isSpace(char c);
};


#endif


#ifndef INTERPRETER_H
#define INTERPRETER_H

using namespace std;

#include <string>
#include <list>
#include <map>
#include "Command.h"

class Interpreter {
    map<string, double> symTbl;
    map<string, Command> cmdMap;

public:
    list<string> lexer(string input);
    void parser();

private:
    bool isSpace(char c);
};


#endif

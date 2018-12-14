
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include "Command.h"

class Interpreter {
    map<string, double> symTbl;
    // example: ‫‪var‬‬ ‫‪roll‬‬ ‫=‬ ‫‪bind‬‬ ‫"‪"/instrumentation/attitude-indicator/indicated-roll-deg‬‬
    map<string, string> symPath;
    map<string, Command*> cmdMap;

public:
    Interpreter();
    ~Interpreter();
    vector< string> lexer(string input);
    void parser(vector<string> input);
    map<string, double> getSymTbl();
    map<string, string> getSymPath();
    map<string, Command*> getCmdMap();

    // helps debugging
    void displayVars();

private:
    bool isSpace(char c);
};


#endif

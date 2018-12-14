
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include "Command.h"

class Interpreter {
    std::map<std::string, double> symTbl;
    std::map<std::string, Command*> cmdMap;

public:
    std::list<std::string> lexer(std::string input);
    void parser();
    std::map<std::string, double> getSymTbl();
    std::map<std::string, Command*> getCmdMap();

    // helps debugging
    void displayVars();

private:
    bool isSpace(char c);
};


#endif

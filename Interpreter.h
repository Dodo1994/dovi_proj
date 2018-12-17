
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include "VarData.h"
#include "Command.h"
#include "CommandFactory.h"
#include "CmdsCollection.h"

class Interpreter {
    map<string, VarData*> symTbl;
    CommandFactory* factory;

public:
    Interpreter();
    ~Interpreter();
    vector< string> lexer(string input);
    void parser(vector<string> input);
};


#endif

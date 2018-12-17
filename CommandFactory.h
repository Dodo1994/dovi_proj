//
// Created by ori on 12/16/18.
//

#ifndef ORI_LEXER_COMMANDFACTORY_H
#define ORI_LEXER_COMMANDFACTORY_H


#include <map>
#include <list>
#include "Command.h"
#include "VarData.h"

class CommandFactory {
    map<string, VarData*>* symTbl;

public:
    CommandFactory(map<string, VarData*>* symTbl);
    Command* createCommand(vector<string>* code, int index);
};


#endif //ORI_LEXER_COMMANDFACTORY_H

//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_CONDITIONCOMMAND_H
#define ORI_LEXER_CONDITIONCOMMAND_H

#include <list>
#include "Command.h"
#include "CommandFactory.h"

class ConditionCommand : public Command{
protected:
    CommandFactory* factory;
    vector<string> *input;
    map<string,VarData*>* data;

public:
    ConditionCommand(CommandFactory* factory, vector<string> *input, map<string,VarData*>* data);
    void doCommand() override = 0;
};


#endif //ORI_LEXER_CONDITIONCOMMAND_H

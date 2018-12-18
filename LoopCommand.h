//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_LOOPCOMMAND_H
#define ORI_LEXER_LOOPCOMMAND_H

#include "ConditionCommand.h"
#include "CommandFactory.h"

class LoopCommand : public ConditionCommand{

public:
    LoopCommand(vector<string> *input,CommandFactory *factory, map<string,VarData*>* data);
    void doCommand();

};


#endif //ORI_LEXER_LOOPCOMMAND_H

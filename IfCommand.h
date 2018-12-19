//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_IFCOMMAND_H
#define ORI_LEXER_IFCOMMAND_H

#include "ConditionCommand.h"

class IfCommand :public ConditionCommand{


public:
    IfCommand(vector<string> *input,CommandFactory *factory, map<string,VarData*>* data);
    void doCommand();

};


#endif //ORI_LEXER_IFCOMMAND_H

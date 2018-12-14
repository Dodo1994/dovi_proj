//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_IFCOMMAND_H
#define ORI_LEXER_IFCOMMAND_H

#include "ConditionCommand.h"

class IfCommand :public ConditionCommand{


public:
    int execute(vector<string> args);

};


#endif //ORI_LEXER_IFCOMMAND_H

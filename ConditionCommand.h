//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_CONDITIONCOMMAND_H
#define ORI_LEXER_CONDITIONCOMMAND_H

#include "Command.h"

class ConditionCommand : public Command{

public:
    int execute(vector<string> code, int index) override = 0;
};


#endif //ORI_LEXER_CONDITIONCOMMAND_H

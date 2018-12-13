//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_LOOPCOMMAND_H
#define ORI_LEXER_LOOPCOMMAND_H

#include "ConditionCommand.h"

class LoopCommand : public ConditionCommand{

public:
    void execute();

};


#endif //ORI_LEXER_LOOPCOMMAND_H

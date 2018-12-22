//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_COMMANDEXPRESSION_H
#define ORI_LEXER_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression{
    Command* command;

public:
    explicit CommandExpression(Command* command);
    double calculate() override;
};


#endif //ORI_LEXER_COMMANDEXPRESSION_H

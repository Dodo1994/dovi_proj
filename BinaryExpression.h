//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_BINARYEXPRESSION_H
#define ORI_LEXER_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression :public Expression{
    Expression* right;
    Expression* left;

public:
    virtual double calculate();
};


#endif //ORI_LEXER_BINARYEXPRESSION_H

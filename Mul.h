//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_MUL_H
#define ORI_LEXER_MUL_H


#include "BinaryExpression.h"

class Mul : public BinaryExpression{

public:
    double calculate() override;

};


#endif //ORI_LEXER_MUL_H

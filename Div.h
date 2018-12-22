//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_DIV_H
#define ORI_LEXER_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression{

public:
    double calculate() override;
};


#endif //ORI_LEXER_DIV_H

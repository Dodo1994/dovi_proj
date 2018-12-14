//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_PLUS_H
#define ORI_LEXER_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression{

public:
    double calculate() override;

};


#endif //ORI_LEXER_PLUS_H

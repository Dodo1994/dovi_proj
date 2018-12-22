//
// Created by ori on 12/19/18.
//

#ifndef ORI_LEXER_BOOLEXPRESSION_H
#define ORI_LEXER_BOOLEXPRESSION_H

using namespace std;

#include <cmath>
#include <string>
#include "BinaryExpression.h"

class BoolExpression : public BinaryExpression{
    string op;

public:
    double calculate();
};


#endif //ORI_LEXER_BOOLEXPRESSION_H

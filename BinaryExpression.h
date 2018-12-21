
#ifndef ORI_LEXER_BINARYEXPRESSION_H
#define ORI_LEXER_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression :public Expression{
protected:
    Expression* right;
    Expression* left;

public:
    void setRight(Expression* right);
    void setLeft(Expression* left);
    virtual double calculate();
};


#endif //ORI_LEXER_BINARYEXPRESSION_H
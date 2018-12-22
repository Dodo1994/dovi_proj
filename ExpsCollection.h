//
// Created by ori on 12/17/18.
//

#ifndef ORI_LEXER_EXPSCOLLECTION_H
#define ORI_LEXER_EXPSCOLLECTION_H


#include "Expression.h"
#include <list>

using namespace std;

class ExpsCollection {
    list<Expression*> expressions;

public:
    ExpsCollection();
    ~ExpsCollection();
    void addExpression(Expression* expression);
    void executeAll();
    void deleteAll();
};


#endif //ORI_LEXER_EXPSCOLLECTION_H

//
// Created by ori on 12/17/18.
//

#ifndef ORI_LEXER_UTILS_H
#define ORI_LEXER_UTILS_H


#include "Expression.h"
#include <string>
#include <map>
#include <list>
#include <vector>
#include "VarData.h"

using namespace std;

class Utils {
public:
    list<string> inFixToPreFix(list<string> inFix);
    list<string> placeValue(list<string> l, map<string, VarData*> *symTbl);
    Expression* preFixToExpression(list<string> preFix);
    Expression* evaluate(list<string> inFix, map<string, VarData *> *symTbl);

    list<string> minusToInt(list<string> l);
};


#endif //ORI_LEXER_UTILS_H

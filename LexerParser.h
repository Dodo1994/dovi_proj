

#ifndef ORI_LEXER_LEXERPARSER_H
#define ORI_LEXER_LEXERPARSER_H


#include "CommandFactory.h"
#include "CommandExpression.h"


class Lexer {
public:
    vector<string> lexer(string input);
};

class Parser {
public:
    void parse(vector<string> &code, ExpsCollection* expressions,
               CommandFactory* factory, map<string,string> &codeMap);
};


#endif //ORI_LEXER_LEXERPARSER_H

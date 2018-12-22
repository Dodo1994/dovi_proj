//
// Created by ori on 12/19/18.
//

#ifndef ORI_LEXER_PARSER_H
#define ORI_LEXER_PARSER_H

using namespace std;

#include <string>
#include <vector>
#include "CommandFactory.h"
#include "ExpsCollection.h"

class Parser {
public:
    void parse(vector<string> &code, ExpsCollection* expressions,
                       CommandFactory* factory, map<string,string> &codeMap);
};


#endif //ORI_LEXER_PARSER_H

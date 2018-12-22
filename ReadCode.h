//
// Created by ori on 12/19/18.
//

#ifndef ORI_LEXER_READCODE_H
#define ORI_LEXER_READCODE_H

using namespace std;

#include <string>
#include <list>
#include <vector>

class ReadCode {

public:
    void readFromFile(string fileName);
    void readFromConsole();
private:
    void displayLexerResult(vector<string> l);
};


#endif //ORI_LEXER_READCODE_H

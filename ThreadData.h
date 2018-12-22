//
// Created by ori on 12/20/18.
//

#ifndef ORI_LEXER_THREADDATA_H
#define ORI_LEXER_THREADDATA_H

#include <string>

using namespace std;

class ThreadData {
    int intArg1;
    int intArg2;
    char* strArg1;

public:
    void setIntArg1(int num);
    void setIntArg2(int num);
    void setStrArg1(char* str);
    int getIntArg1();
    int getIntArg2();
    char* getStrArg1();
};


#endif //ORI_LEXER_THREADDATA_H

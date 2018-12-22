//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_CONNECTCOMMAND_H
#define ORI_LEXER_CONNECTCOMMAND_H

#include <map>
#include "Command.h"
#include "VarData.h"
#include "Threads.h"

class ConnectCommand: public Command {
    char* ip;
    double port;
    Threads* threads;

public:
    ConnectCommand(vector <string> &code, map<string, VarData *> *symTbl, Threads* threads);
    void doCommand();
};


#endif //ORI_LEXER_CONNECTCOMMAND_H

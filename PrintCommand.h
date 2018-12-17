//
// Created by ori on 12/16/18.
//

#ifndef ORI_LEXER_PRINTCOMMAND_H
#define ORI_LEXER_PRINTCOMMAND_H


#include "Command.h"
#include "VarData.h"

class PrintCommand : public Command {
    string msg;
    map<string, string>* symTbl;

public:
    PrintCommand(vector<string>* code, int index, map<string, VarData*>* symTbl);
    void doCommand() override;
};


#endif //ORI_LEXER_PRINTCOMMAND_H

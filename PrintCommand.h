//
// Created by ori on 12/16/18.
//

#ifndef ORI_LEXER_PRINTCOMMAND_H
#define ORI_LEXER_PRINTCOMMAND_H


#include <list>
#include "Command.h"
#include "VarData.h"

class PrintCommand : public Command {
    list<string> strings;
    map<string, VarData*>* symTbl;

public:
    PrintCommand(vector<string> &code, map<string, VarData*> *symTbl);
    void doCommand() override;
};


#endif //ORI_LEXER_PRINTCOMMAND_H

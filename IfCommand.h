//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_IFCOMMAND_H
#define ORI_LEXER_IFCOMMAND_H

#include "ConditionCommand.h"

class IfCommand :public ConditionCommand {
    ExpsCollection* expressions;
    vector<string> code;
    CommandFactory *factory;
    map<string, VarData *> *symTbl;
    map<string, string> cmdMap;

public:
    void doCommand() override;

    IfCommand(vector<string> &code, CommandFactory *factory, map<string, VarData *> *symTbl, map<string, string> &cmdMap);
    ~IfCommand();
};
#endif //ORI_LEXER_IFCOMMAND_H

//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_LOOPCOMMAND_H
#define ORI_LEXER_LOOPCOMMAND_H

#include "ConditionCommand.h"
#include "ExpsCollection.h"

class LoopCommand : public ConditionCommand{
    ExpsCollection* expressions;
    vector<string> code;
    CommandFactory* factory;
    map<string,string> cmdMap;
    map<string, VarData*>* symTbl;

public:
    explicit LoopCommand(vector<string> &code, CommandFactory* factory,
            map<string, VarData*> *symTbl, map<string,string> &cmdMap);
    void doCommand() override;

};


#endif //ORI_LEXER_LOOPCOMMAND_H

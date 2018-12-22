
#ifndef ORI_LEXER_DEFINEVARCOMMAND_H
#define ORI_LEXER_DEFINEVARCOMMAND_H

#include <map>
#include <list>
#include "Command.h"
#include "VarData.h"

class DefineVarCommand : public Command{
    map<string, VarData*>* symTbl;
    string name;
    string path;
    double value;

public:
    explicit DefineVarCommand(vector<string> &code, map<string, VarData*> *symTbl);
    void doCommand() override;
};

#endif


#ifndef ORI_LEXER_DEFINEVARCOMMAND_H
#define ORI_LEXER_DEFINEVARCOMMAND_H

#include <map>
#include "Command.h"
#include "VarData.h"

class DefineVarCommand : public Command{
    map<string, VarData*>* symTbl;

public:
    explicit DefineVarCommand(vector<string> code, map<string, VarData*>* symTbl);
    int doCommand() override;
};

#endif

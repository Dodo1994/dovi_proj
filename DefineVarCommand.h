
#ifndef ORI_LEXER_DEFINEVARCOMMAND_H
#define ORI_LEXER_DEFINEVARCOMMAND_H

#include <map>
#include "Command.h"

class DefineVarCommand : public Command{
    map<string, string>* symPath;

public:
    explicit DefineVarCommand(map<string, string>* symPath);
    int execute(vector<string> code, int index) override;
};

#endif

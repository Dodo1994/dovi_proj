
#ifndef ORI_LEXER_DEFINEVARCOMMAND_H
#define ORI_LEXER_DEFINEVARCOMMAND_H

#include <map>
#include "Command.h"

class DefineVarCommand : public Command{
    std::map<std::string, double> symTbl;

public:
    explicit DefineVarCommand(std::vector<std::string> args, std::map<std::string, double> symTbl);
    void execute();
};

#endif

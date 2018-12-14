
#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    // assume vector args[0] = varName, args[1] = varValue as strind (stod should convert to double)
    this->interpreter->getSymTbl().insert(pair<string,double>(this->args[0],stod(this->args[1])));
}
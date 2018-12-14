#include <utility>

#include <utility>


#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    // assume vector args[0] = varName, args[1] = varValue as strind (stod should convert to double)
    this->symTbl.insert(std::pair<std::string,double>(this->args[0],std::stod(this->args[1])));
}

DefineVarCommand::DefineVarCommand(std::vector<std::string> args, std::map<std::string, double> symTbl) : Command(std::move(args)) {
    this->symTbl = move(symTbl);
}

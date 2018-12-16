#include <utility>

#include <utility>


#include "DefineVarCommand.h"

int DefineVarCommand::doCommand() {
    // assume vector args[index+1] = varName, args[index+4] = varPath
    //this->symTbl->insert(pair<string,string>(code[index+1], code[index+4]));
    return 5;//add to index
}

DefineVarCommand::DefineVarCommand(vector<string> code, map<string, VarData*>* symTbl) {
    this->symTbl = symTbl;
}

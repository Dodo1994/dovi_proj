#include <utility>

#include <utility>


#include "DefineVarCommand.h"

int DefineVarCommand::execute(vector<string> code, int index) {
    // assume vector args[index+1] = varName, args[index+4] = varPath
    this->symPath->insert(pair<string,string>(code[index+1], code[index+4]));
    return 5;//add to index
}

DefineVarCommand::DefineVarCommand(map<string, string> *symPath) {
    this->symPath = symPath;
}

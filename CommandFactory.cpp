

#include <iostream>
#include "CommandFactory.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"

CommandFactory::CommandFactory(map<string, VarData *>* symTbl) {
    this->symTbl=symTbl;
}

Command *CommandFactory::createCommand(vector<string>* code, int index) {
    if((*code)[index]=="openDataServer") {

    } else if ((*code)[index]=="connect") {

    } else if ((*code)[index]=="var") {
        return new DefineVarCommand(code, index, this->symTbl);
    } else if ((*code)[index]=="=") {

    } else if ((*code)[index]=="while") {

    } else if ((*code)[index]=="if") {

    } else if ((*code)[index]=="sleep") {

    } else if ((*code)[index]=="print") {
        return new PrintCommand(code, index, this->symTbl);
    }

    return nullptr;
}

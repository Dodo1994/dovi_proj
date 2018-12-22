

#include <iostream>
#include "CommandFactory.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "PlacementCommand.h"
#include "LoopCommand.h"
#include "IfCommand.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"


CommandFactory::CommandFactory(map<string, VarData *> *symTbl, map<string, string> &cmpMap, Threads* threads) {
    this->symTbl=symTbl;
    this->cmdMap=cmpMap;
    this->threads=threads;
}

Command *CommandFactory::createCommand(vector<string> &code) {
    int index = 0;
    if (code[index] == "openDataServer") {
        return new OpenServerCommand(code, this->symTbl, this->threads);
    } else if (code[index] == "connect") {
        return new ConnectCommand(code, this->symTbl, this->threads);
    } else if (code[index] == "var") {
        return new DefineVarCommand(code, this->symTbl);
    } else if (code[index] == "while") {
        return new LoopCommand(code, this, this->symTbl, this->cmdMap);
    } else if (code[index] == "if") {
        return new IfCommand(code, this, this->symTbl, this->cmdMap);
    } else if (code[index] == "sleep") {

    } else if (code[index] == "print") {
        return new PrintCommand(code, this->symTbl);
    } else if (code[index+1] == "=") {
        return new PlacementCommand(code, this->symTbl);
    }

    return nullptr;
}



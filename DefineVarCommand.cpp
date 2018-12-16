#include <utility>

#include <utility>


#include "DefineVarCommand.h"

void DefineVarCommand::doCommand() {
    this->symTbl->insert(pair<string, VarData*>(this->name, new VarData(this->value, this->path)));
}

DefineVarCommand::DefineVarCommand(vector<string> code, int index, map<string, VarData*>* symTbl) {
    this->symTbl = symTbl;

    /**
     * handle 2 options:
     * 1. var breaks = bind "/controls/flight/speedbrake"
     * 2. ‫‪var‬‬ ‫‪h0‬‬ ‫=‬ ‫‪heading‬‬
     */

    this->name=code[index+1];

    if(code[index+3]=="bind"){
        this->path=code[index+4];
        this->value=0;
    } else {
        this->path=this->symTbl->at(code[3])->getPath();
        this->value=this->symTbl->at(code[3])->getValue();
    }
}



//================================================================
// tried list:

/**
     * example: var breaks = bind "/controls/flight/speedbrake"
     * we need code[1] (breaks) and code[4] (path)


auto it=code.begin();
// code[1]
this->name=*(++it);
it++, it++, it++;
// code[4]
this->path=*it;
// default
this->value=0;

 */
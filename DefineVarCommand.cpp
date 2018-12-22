#include <utility>

#include <utility>


#include "DefineVarCommand.h"

void DefineVarCommand::doCommand() {
    this->symTbl->insert(pair<string, VarData*>(this->name, new VarData(this->value, this->path)));
}

DefineVarCommand::DefineVarCommand(vector<string> &code, map<string, VarData *> *symTbl) {
    this->symTbl = symTbl;

    /**
     * handle 2 options:
     * 1. var breaks = bind "/controls/flight/speedbrake"
     * 2. ‫‪var‬‬ ‫‪h0‬‬ ‫=‬ ‫‪heading‬‬
     */

    this->name = code[1];

    if (code[3] == "bind") {
        // var x = bind "bla bla"
        if (code[4][0] == '"') {
            this->path = code[4];
            this->value = 0;
            // var x = bind y
        } else {
            this->path = this->symTbl->at(code[4])->getPath();
            this->value = this->symTbl->at(code[4])->getValue();
        }
    } else {
        this->path = "/";
        // var x = y
        if(symTbl->count(code[3])) {
            this->value = this->symTbl->at(code[3])->getValue();
        // var x = 5
        } else {
            list<string> expList;
            expList.push_back(code[3]);
            int index = 4;
            while (index<code.size() &&code[index]!=";"){
                expList.push_back(code[index]);
                index++;
                expList.push_back(code[index]);
                index++;
            }
        }
    }
}

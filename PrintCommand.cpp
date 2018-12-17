
#include <iostream>
#include <map>
#include "PrintCommand.h"

void PrintCommand::doCommand() {
    cout << msg << endl;
}

PrintCommand::PrintCommand(vector<string> *code, int index, map<string, VarData *> *symTbl) {
    if((*code)[index+1][0]=='"'){
        for (int i = 1; i < (*code)[index+1].size()-1; ++i) {
            this->msg += (*code)[index+1][i];
        }
    } else {
        this->msg = to_string(symTbl->at((*code)[index+1])->getValue());
    }
}

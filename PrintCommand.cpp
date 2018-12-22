
#include <iostream>
#include <map>
#include "PrintCommand.h"
#include "Utils.h"

void PrintCommand::doCommand() {
    if((*strings.begin())[0] == '"'){
        for (int i = 1; i < (*strings.begin()).size()-1; ++i) {
            cout<<(*strings.begin())[i];
        }
        cout << endl;
    } else {
        Utils utils;
        cout<<to_string(utils.evaluate(this->strings, this->symTbl)->calculate())<<endl;
    }
}

PrintCommand::PrintCommand(vector<string>& code, map<string, VarData *> *symTbl) {
    this->symTbl=symTbl;
    vector<string>::iterator it=code.begin();
    it++;
    for (it; it!=code.end(); ++it) {
        this->strings.push_back(*it);
    }
}

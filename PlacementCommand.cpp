#include "PlacementCommand.h"
#include "Expression.h"
#include "Utils.h"


void PlacementCommand::doCommand() {
//    if(this->symTbl->count(*this->right.begin())){
//        this->symTbl->at(this->left)->setValue(this->symTbl->at(*this->right.begin())->getValue());
//        this->symTbl->at(this->left)->setPath(this->symTbl->at(*this->right.begin())->getPath());
//    } else {
    Utils utils;
    // use shunting yard in utils to get expression from str
    this->symTbl->at(this->left)->setValue(utils.evaluate(this->right,this->symTbl)->calculate());
    //}
}

PlacementCommand::PlacementCommand(vector<string> code, map<string, VarData *> *symTbl) {
    int index=1;
    this->symTbl=symTbl;
    this->left=code[index-1];
    ++index;
    //TODO no need to check end line
    while (index<code.size()){
        this->right.push_back(code[index]);
        ++index;
    }
}
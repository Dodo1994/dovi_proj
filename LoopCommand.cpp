
#include "LoopCommand.h"
#include "CommandFactory.h"
#include "Utils.h"
#include "Parser.h"


void LoopCommand::doCommand() {
    int index = 1;
    Utils utils;
    Parser parser;
    list<string> condition;
    vector<string> blockCode;

    while (this->code[index] != "{") {
        condition.push_back(this->code[index]);
        index++;
    }
    index += 2;
    for (index; index < this->code.size(); ++index) {
        blockCode.push_back(this->code[index]);
    }

    while (utils.evaluate(condition, this->symTbl)->calculate()) {
        this->expressions->deleteAll();
        parser.parse(blockCode, this->expressions, this->factory, this->cmdMap);
        this->expressions->executeAll();
    }
}

LoopCommand::LoopCommand(vector<string> &code, CommandFactory *factory, map<string, VarData *> *symTbl, map<string,string> *cmdMap) {
    for (const auto &i : code) {
        this->code.push_back(i);
    }
    this->factory=factory;
    this->symTbl=symTbl;
    this->cmdMap= cmdMap;
    this->expressions = new ExpsCollection;
}
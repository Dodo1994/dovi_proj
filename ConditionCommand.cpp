//
// Created by ori on 12/14/18.
//

#include "ConditionCommand.h"

ConditionCommand::ConditionCommand(CommandFactory *factory, vector<string> *input, map<string, VarData *> *data) {
    this->factory = factory;
    this->input = input;
    this->data = data;
}

//
// Created by ori on 12/14/18.
//

#include "IfCommand.h"

void IfCommand::doCommand() {
    int index = 1;
    list<string> expressions;
    while ((*input)[index] != "{") {
        expressions.push_back((*input)[index]);
        index++;
    }
    Utils utils;
    if (utils.evaluate(expressions, data).calculate()) {
        int i = index + 2;
        Command *command;
        vector<string> commandCode;
        while (i < (*input).size()) {
            commandCode.clear();
            commandCode.push_back((*input)[i]);
            i++;
            while ((*input)[i] != ";") {
                commandCode.push_back((*input)[i]);
                i++;
            }
            i++;
            if (command = this->factory->createCommand(commandCode)) {
                command->doCommand();
            }
        }
    }
}

IfCommand::IfCommand(vector<string> *input, CommandFactory *factory, map<string, VarData *> *data) : ConditionCommand(
        factory, input, data) {}

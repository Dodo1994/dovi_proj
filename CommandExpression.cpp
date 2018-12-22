//
// Created by ori on 12/14/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate() {
    this->command->doCommand();
}

CommandExpression::CommandExpression(Command* command) {
    this->command = command;
}

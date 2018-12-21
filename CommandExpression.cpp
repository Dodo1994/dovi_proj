#include "CommandExpression.h"

double CommandExpression::calculate() {
    this->command->doCommand();
}

CommandExpression::CommandExpression(Command* command) {
    this->command = command;
}
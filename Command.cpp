

#include "Command.h"

Command::Command(vector<string> args, Interpreter *interpreter) {
    this->args=move(args);
    this->interpreter=interpreter;
}

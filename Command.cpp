

#include "Command.h"

Command::Command(std::vector<std::string> args) {
    this->args=move(args);
}

void Command::execute() {

}

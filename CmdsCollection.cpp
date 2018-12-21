
#include "CmdsCollection.h"

void CmdsCollection::addCommand(Command *command) {
    this->commands.push_front(command);
}

CmdsCollection::~CmdsCollection() {
    for (auto &c : this->commands) {
        delete c;
    }
}

void CmdsCollection::doCommands() {
    for (auto &c : this->commands) {
        c->doCommand();
    }
}
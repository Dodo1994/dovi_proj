#include <utility>

//
// Created by ori on 12/14/18.
//

#include "ConnectCommand.h"

void ConnectCommand::doCommand() {

}

ConnectCommand::ConnectCommand(string ip, int port) {
    this->ip= move(ip);
    this->port=port;
}

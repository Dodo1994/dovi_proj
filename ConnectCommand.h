//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_CONNECTCOMMAND_H
#define ORI_LEXER_CONNECTCOMMAND_H

#include "Command.h"

class ConnectCommand: public Command {
    string ip;
    int port;

public:
    ConnectCommand(string ip, int port);
    void doCommand();
};


#endif //ORI_LEXER_CONNECTCOMMAND_H

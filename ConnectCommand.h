//
// Created by ori on 12/14/18.
//

#ifndef ORI_LEXER_CONNECTCOMMAND_H
#define ORI_LEXER_CONNECTCOMMAND_H

#include "Command.h"

class ConnectCommand: public Command {

public:
    int execute(vector<string> code, int index);
};


#endif //ORI_LEXER_CONNECTCOMMAND_H

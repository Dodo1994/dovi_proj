

#ifndef ORI_LEXER_OPENSERVERCOMMAND_H
#define ORI_LEXER_OPENSERVERCOMMAND_H

#include "Command.h"

class OpenServerCommand : Command{
    int port;
    int rate;

public:
    OpenServerCommand(int port, int rate);
    void doCommand() override;

};


#endif //ORI_LEXER_OPENSERVERCOMMAND_H

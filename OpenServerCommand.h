

#ifndef ORI_LEXER_OPENSERVERCOMMAND_H
#define ORI_LEXER_OPENSERVERCOMMAND_H

#include "Command.h"

class OpenServerCommand : Command{

public:
    int execute(vector<string> code, int index) override;

};


#endif //ORI_LEXER_OPENSERVERCOMMAND_H

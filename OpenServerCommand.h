

#ifndef ORI_LEXER_OPENSERVERCOMMAND_H
#define ORI_LEXER_OPENSERVERCOMMAND_H

#include <list>
#include <map>
#include "Command.h"
#include "Expression.h"
#include "VarData.h"
#include "Threads.h"

class OpenServerCommand : public Command{
    int port;
    int rate;
    map<string, VarData*>* symTbl;
    Threads* threads;

public:
    OpenServerCommand(vector<string>& code, map<string, VarData*> *symTbl, Threads* threads);
    void doCommand() override;
};


#endif //ORI_LEXER_OPENSERVERCOMMAND_H

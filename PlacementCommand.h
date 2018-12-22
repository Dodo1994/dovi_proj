//
// Created by ori on 12/17/18.
//

#ifndef ORI_LEXER_PLACEMENTCOMMAND_H
#define ORI_LEXER_PLACEMENTCOMMAND_H

#include <map>
#include <list>
#include "Command.h"
#include "VarData.h"

class PlacementCommand : public Command {
    map<string, VarData*>* symTbl;
    string left;
    list<string> right;

public:
    explicit PlacementCommand(vector<string> &code, map<string, VarData*> *symTbl);
    void doCommand() override;

};


#endif //ORI_LEXER_PLACEMENTCOMMAND_H

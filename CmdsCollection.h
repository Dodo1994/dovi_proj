//
// Created by ori on 12/16/18.
//

#ifndef ORI_LEXER_CMDSCOLLECTION_H
#define ORI_LEXER_CMDSCOLLECTION_H


#include <list>
#include "Command.h"


/** PROBLEM!! NEED REALTIME UPDATED MAP!!!!!!!! **/


class CmdsCollection {
    list<Command*> commands;

public:
    void addCommand(Command* command);
    ~CmdsCollection();
    void doCommands();
};


#endif //ORI_LEXER_CMDSCOLLECTION_H

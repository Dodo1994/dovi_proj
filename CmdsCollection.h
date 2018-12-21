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

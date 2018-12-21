#include <list>
#include "Command.h"
#include "CommandFactory.h"

class ConditionCommand : public Command{

public:
    ConditionCommand();
    void doCommand() override = 0;
};
#include <list>
#include "Command.h"
#include "VarData.h"

class PrintCommand : public Command {
    list<string> strings;
    map<string, VarData*>* symTbl;

public:
    PrintCommand(vector<string> &code, map<string, VarData*>* symTbl);
    //PrintCommand(vector<string>* code, int index, map<string, VarData*>* symTbl);
    void doCommand() override;
};
#include <map>
#include <list>
#include "Command.h"
#include "VarData.h"

class PlacementCommand : public Command {
    map<string, VarData*>* symTbl;
    string left;
    list<string> right;

public:
    //explicit PlacementCommand(vector<string>* code, int index, map<string, VarData*>* symTbl);
    explicit PlacementCommand(vector<string> code, map<string, VarData*>* symTbl);
    void doCommand() override;

};
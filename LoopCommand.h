#include "ConditionCommand.h"
#include "ExpsCollection.h"

class LoopCommand : public ConditionCommand{
    ExpsCollection* expressions;
    vector<string> code;
    CommandFactory* factory;
    map<string,string>* cmdMap;
    map<string, VarData*>* symTbl;

public:
    explicit LoopCommand(vector<string> &code, CommandFactory* factory,
                         map<string, VarData*>* symTbl, map<string,string> *cmdMap);
    void doCommand() override;

};

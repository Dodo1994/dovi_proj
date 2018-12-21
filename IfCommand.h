#include "ConditionCommand.h"

class IfCommand :public ConditionCommand {
    ExpsCollection* expressions;
    vector<string> code;
    CommandFactory *factory;
    map<string, VarData *> *symTbl;
    map<string, string> *cmdMap;

public:
    void doCommand() override;

    IfCommand(vector<string> &code, CommandFactory *factory, map<string, VarData *> *symTbl, map<string, string> *cmdMap);
    ~IfCommand();
};
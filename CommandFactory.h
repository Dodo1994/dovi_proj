#include <map>
#include <list>
#include "Command.h"
#include "VarData.h"
#include "ExpsCollection.h"
#include "Threads.h"

class CommandFactory {
    map<string, VarData*>* symTbl;
    map<string,string>* cmdMap;
    Threads* threads;

public:
    CommandFactory(map<string, VarData*>* symTbl, map<string,string>* cmpMap, Threads* threads);
    Command* createCommand(vector<string> &code);
};


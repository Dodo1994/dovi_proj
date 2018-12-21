#include <map>
#include "Command.h"
#include "VarData.h"
#include "Threads.h"

class ConnectCommand: public Command {
    char* ip;
    double port;
    Threads* threads;

public:
    ConnectCommand(vector <string> &code, map<string, VarData *> *symTbl, Threads* threads);
    void doCommand();
};

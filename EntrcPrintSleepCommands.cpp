

#include "EntrcPrintSleepCommands.h"


void EntrcCommand::doCommand() {
    getchar();
}

void PrintCommand::doCommand() {
    Utils utils;
    if ((*strings.begin())[0] == '"') {
        cout << utils.removeApostrophes(*strings.begin()) << endl;
    } else {
        cout << to_string(utils.evaluate(this->strings, this->symTbl)) << endl;
    }
}

PrintCommand::PrintCommand(vector<string>& code, map<string, VarData *> *symTbl) {
    this->symTbl = symTbl;
    auto it = code.begin();
    it++;
    for (it; it != code.end(); ++it) {
        this->strings.push_back(*it);
    }
}

void SleepCommand::doCommand() {
    usleep(this->sleepTime);
}

SleepCommand::SleepCommand(vector<string>& code, map<string, VarData *> *symTbl) {
    Utils utils;
    list<string> sleepList;
    auto it = code.begin();
    it++;
    for (it; it != code.end(); ++it) {
        sleepList.push_back(*it);
    }
    this->sleepTime = utils.evaluate(sleepList, symTbl);
}

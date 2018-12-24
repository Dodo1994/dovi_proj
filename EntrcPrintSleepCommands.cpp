

#include "EntrcPrintSleepCommands.h"


void EntrcCommand::doCommand() {
    // wait until get char
    getchar();
}

void PrintCommand::doCommand() {
    Utils utils;

    // case print "dovi" display dovi
    if ((*this->strings.begin())[0] == '"') {
        cout << utils.removeApostrophes(*strings.begin()) << endl;
        // case print expression display expression's value
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
    usleep(static_cast<__useconds_t>(this->sleepTime));
}

SleepCommand::SleepCommand(vector<string>& code, map<string, VarData *> *symTbl) {
    Utils utils;
    list<string> sleepList;

    //
    auto it = ++code.begin();
    for (it; it != code.end(); ++it) {
        sleepList.push_back(*it);
    }
    this->sleepTime = static_cast<int>(utils.evaluate(sleepList, symTbl));
}

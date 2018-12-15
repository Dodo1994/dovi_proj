
#include "Interpreter.h"
#include "DefineVarCommand.h"

vector<string> Interpreter::lexer(string input) {
    int i = 0;
    string word;
    bool isFirstSpace = true;
    vector<string> words;

    // pass over input
    while (i < input.size()) {
        // pass over spaces
        while (isSpace(input[i]) && i < input.size()) {
            // if first space after word
            if(isFirstSpace) {
                isFirstSpace = false;
                // add word and init word
                words.push_back(word);
                word = "";
            }
            ++i;
        }
        // add char to word
        word+=input[i];
        // init first space
        isFirstSpace = true;
        ++i;
    }
    // add last word
    words.push_back(word);

    return words;
}

void Interpreter::parser(vector<string> input) {

    /**
     * Hi Dovi!!
     * there are 3 maps members of the interpreter (do you think to put them elsewhere?)
     * map<string, double> getSymTbl();
     * map<string, string> getSymPath();
     * map<string, Command*> getCmdMap();
     *
     * here it is a loop to pass over the code and call commands. BUG!! call only first command
     * pay attention there is no need in '/n' to mark newline
     *
     *
     * command get 2 args: the whole code vector and current index. do you think about something else?
     *
     */

    int i = 0;
    Command* command;
    while (i<input.size()) {
        cout<<i;
        if(this->cmdMap.count(input[i])) { // bug execute only first var
            command = this->cmdMap.at(input[i]);
            i+=command->execute(input,i);
        }else {
            i++;
        }
    }


    /**
     * from eli slides:
     *
     *  Command interface with function execute(string):int
     *
     *
     *  MAP <string,Command> for commands
     *
     *  openDataServer = OpenServerCommand
     *  connect = ConnectCommand
     *  var = DefineVarCommand
     *
     * Command c = map.get(array[index]);
     * if(c!=null)
     *  index += c.execute(array[index]);
     *
     *
     *  MAP <string,Double> for vars
     *
     *  brakes -> 0
     *
     *  throttle = 1
     *  symTbl.put("throttle", 1.0)
     *
     *
     * More Commands
     *
     */

}

bool Interpreter::isSpace(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

map<string, double> Interpreter::getSymTbl() {
    return this->symTbl;
}

map<string, Command*> Interpreter::getCmdMap() {
    return this->cmdMap;
}

void Interpreter::displayVars() {
    cout<<endl;
    for (auto &it : this->symPath)
        cout << it.first << "," << it.second << endl;
}

Interpreter::Interpreter() {
    Command* c1 = new DefineVarCommand(&this->symPath);
    this->cmdMap.insert(pair<string, Command*>("var", c1));
}

Interpreter::~Interpreter() {

    map<string, int>::iterator it;

    for (auto &it : this->cmdMap) {
        if (it.second != NULL) {
            delete(it.second);
        }
    }
}

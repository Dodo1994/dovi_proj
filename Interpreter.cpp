
#include "Interpreter.h"

list <string> Interpreter::lexer(string input) {
    int i = 0;
    string word;
    bool isFirstSpace = true;
    list<string> words;

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

void Interpreter::parser() {

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
    return (c == ' ' || c == '\t'); //‫‪ c == '\n' not space, to mark new line
}

map<string, double> Interpreter::getSymTbl() {
    return this->symTbl;
}

map <string, Command> Interpreter::getCmdMap() {
    return this->cmdMap;
}

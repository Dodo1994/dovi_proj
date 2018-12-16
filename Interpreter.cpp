
#include "Interpreter.h"
#include "DefineVarCommand.h"

vector<string> Interpreter::lexer(string input) {
    int i = 0;
    string word;
    bool isFirstBlank = true;
    bool isPath = false;
    vector<string> words;

    // pass over input
    while (i < input.size()) {
        // case " set flag that -,/ etc. aren't operators
        if(input[i] == '"'){
            isPath = true;
        }
        // mark end line with ;
        if (input[i] == '\n') {
            if(word!="") {
                words.push_back(word);
                word="";
            }
            words.push_back(";");
            isFirstBlank= true;
            isPath= false;
            // operators
        } else if (input[i] == '+' || input[i] == '%' || input[i] == '('|| input[i] == ')') {
            if(word!="") {
                words.push_back(word);
                word="";
            }
            words.push_back(string(1,input[i]));
            // case not in path, /,- are operators
        } else if(!isPath && (input[i]=='/' || input[i]=='-')){
            if(word!="") {
                words.push_back(word);
                word="";
            }
            words.push_back(string(1,input[i]));
            // blanks
        } else if (input[i] == ' ' || input[i] == '\t') {
            if(isFirstBlank && word!="") {
                words.push_back(word);
                word = "";
                isFirstBlank = false;
            }
            //regular chars
        } else {
            word+=input[i];
            isFirstBlank= true;
        }
        i++;
    }
    // add last word
    words.push_back(word);

    return words;
}

void Interpreter::parser(vector<string> input) {

    int i = 0;
    Command* command;
    while (i<input.size()) {
        cout<<i;
        if(this->cmdMap.count(input[i])) { // bug doCommand only first var
            command = this->cmdMap.at(input[i]);
            i+= command->doCommand();//fix send only args and not whole input
        } else {
            i++;
        }
    }

}

Interpreter::Interpreter() {
    this->factory = new CommandFactory(&this->symTbl);
}

Interpreter::~Interpreter() {
    delete this->factory;
}

/**
 * FACTORY!!!!!!!!!!!!!!!!!!!
 */



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
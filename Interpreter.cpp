
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
        if(input[i] == '"'){
            isPath = true;
        }
        if (input[i] == '\n') {
            if(word!="") {
                words.push_back(word);
                word="";
            }
            words.push_back(";");
            isFirstBlank= true;
            isPath= false;
        } else if (input[i] == '+' || input[i] == '%' || input[i] == '('|| input[i] == ')') {
            if(word!="") {
                words.push_back(word);
                word="";
            }
            words.push_back(string(1,input[i]));
            isFirstBlank= true;
        } else if(!isPath && (input[i]=='/' || input[i]=='-')){
            if(word!="") {
                words.push_back(word);
                word="";
            }
            words.push_back(string(1,input[i]));
            isFirstBlank= true;
        } else if (input[i] == ' ' || input[i] == '\t') {
            if(isFirstBlank && word!="") {
                words.push_back(word);
                word = "";
                isFirstBlank = false;
            }
        } else {
            word+=input[i];
            cout<<word;
            isFirstBlank= true;
        }
        i++;
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
        if(this->cmdMap.count(input[i])) { // bug doCommand only first var
            command = this->cmdMap.at(input[i]);
            i+= command->doCommand();//fix send only args and not whole input
        } else {
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

Interpreter::Interpreter() {
    this->factory = new CommandFactory(&this->symTbl);
}

Interpreter::~Interpreter() {
    delete this->factory;
}

/**
 * FACTORY!!!!!!!!!!!!!!!!!!!
 */

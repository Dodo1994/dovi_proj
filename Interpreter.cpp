
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

void Interpreter::parser(vector<string> code) {
    // i didn't succeed to send a shorter arr. tried list but lots of problems :(
    int index = 0, j;
    Command* command;
    while (index<code.size()) {
        // not null iff this is a word of command
        if(command = this->factory->createCommand(code, index)){
            this->commands->addCommand(command);
        }
        ++index;
    }

    // run commands
    this->commands->doCommands();
}

Interpreter::Interpreter() {
    this->factory = new CommandFactory(&this->symTbl);
    this->commands = new CmdsCollection();
}

Interpreter::~Interpreter() {
    delete this->factory;
    delete this->commands;
    for (auto &it : this->symTbl) {
        delete it.second;
    }
}
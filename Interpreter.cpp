
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
        if (input[i] == '"') {
            isPath = true;
        }
        // mark end line with ;
        if (input[i] == '\n') {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
            words.push_back(";");
            isFirstBlank = true;
            isPath = false;
            // operators
        } else if (input[i] == '=' || input[i] == '+' || input[i] == '%' || input[i] == '(' || input[i] == ')') {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
            words.push_back(string(1, input[i]));
            // case not in path, /,- are operators
        } else if (!isPath && (input[i] == '/' || input[i] == '-')) {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
            words.push_back(string(1, input[i]));
            // blanks
        } else if (input[i] == ' ' || input[i] == '\t') {
            if (isFirstBlank && word != "") {
                words.push_back(word);
                word = "";
                isFirstBlank = false;
            }
            //regular chars
        } else {
            word += input[i];
            isFirstBlank = true;
        }
        i++;
    }
    // add last word
    words.push_back(word);

    return words;
}

void Interpreter::parser(vector<string> code) {
    int index = 0;
    Command *command;
    vector<string> commandCode;
    while (index < code.size()) {
        if (this->codeMap.count(code[index])) {
            if (this->codeMap[code[index]] == "command") {
                commandCode.clear();
                commandCode.push_back(code[index]);
                index++;
                while (code[index] != ";") {
                    commandCode.push_back(code[index]);
                    index++;
                }
                index++;
                if(command = this->factory->createCommand(commandCode)){
                    command->doCommand();
                }

            } else {
                commandCode.clear();
                commandCode.push_back(code[index]);
                index++;
                while (code[index] != "}") {
                    commandCode.push_back(code[index]);
                    index++;
                }
                index += 2;
                if(command = this->factory->createCommand(commandCode)){
                    command->doCommand();
                }
            }
        }
    }

    // tried to add to collection and run all commands after, but there is a problem
    // need updated map in realtime
}

Interpreter::Interpreter() {
    this->factory = new CommandFactory(&this->symTbl);
    this->codeMap["var"] = "command";
    this->codeMap["openDataServer"] = "command";
    this->codeMap["connect"] = "command";
    this->codeMap["print"] = "command";
    this->codeMap["sleep"] = "command";
    this->codeMap["while"] = "condition";
    this->codeMap["if"] = "condition";
}

Interpreter::~Interpreter() {
    delete this->factory;
    // free al VarData
    for (auto &it : this->symTbl)
        delete it.second;
}

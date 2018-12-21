#include "Interpreter.h"
#include "DefineVarCommand.h"
#include "CommandExpression.h"
#include "Parser.h"

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
        } else if (input[i] == '+' || input[i] == '*' || input[i] == '(' || input[i] == ')') {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
            words.push_back(string(1, input[i]));

        } else if (input[i] == '=' || input[i] == '<' || input[i] == '>') {
            if (input[i + 1] == '=') {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
                word = input[i] + input[i + 1];
                words.push_back(word);
                word = "";
                i++;
            } else {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
                words.push_back(string(1, input[i]));
            }
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
    this->expressions->deleteAll();
    Parser parser;
    parser.parse(code, this->expressions, this->factory, &this->codeMap);
    this->expressions->executeAll();
}

Interpreter::Interpreter() {
    this->codeMap["var"] = "command";
    this->codeMap["openDataServer"] = "command";
    this->codeMap["connect"] = "command";
    this->codeMap["print"] = "command";
    this->codeMap["sleep"] = "command";
    this->codeMap["while"] = "condition";
    this->codeMap["if"] = "condition";
    this->codeMap["="] = "command";
    this->expressions = new ExpsCollection();
    this->threads = new Threads;
    this->factory = new CommandFactory(&this->symTbl, &this->codeMap, this->threads);
}

Interpreter::~Interpreter() {
    delete this->factory;
    delete this->expressions;
    // free al VarData
    for (auto &it : this->symTbl)
        delete it.second;
    delete this->threads;
}
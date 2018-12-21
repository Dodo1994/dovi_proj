#include "Parser.h"
#include "CommandExpression.h"

//TODO handle while within while count } to be like {

void Parser::parse(vector<string> &code, ExpsCollection *expressions, CommandFactory *factory,
                   map<string, string> *codeMap) {
    int index = 0;
    if(code.size() > 0 && code[code.size()-1]!=";") {
        code.push_back(";");
    }
    vector<string> commandCode;
    while (index < code.size()) {
        if ((*codeMap).count(code[index])) {
            if ((*codeMap)[code[index]] == "command") {
                commandCode.clear();
                commandCode.push_back(code[index]);
                index++;
                while (index < code.size() && code[index] != ";") {
                    commandCode.push_back(code[index]);
                    index++;
                }
                index++;
                expressions->addExpression(new CommandExpression(factory->createCommand(commandCode)));
                // case command with block
            } else {
                commandCode.clear();
                commandCode.push_back(code[index]);
                index++;
                while (index < code.size() && code[index] != "}") {
                    commandCode.push_back(code[index]);
                    index++;
                }
                index += 2;
                expressions->addExpression(new CommandExpression(factory->createCommand(commandCode)));
            }
            // case command word is the second word ("=")
        } else if (code.size()>1 && (*codeMap).count(code[index+1])) {
            commandCode.clear();
            commandCode.push_back(code[index]);
            index++;
            while (code[index] != ";") {
                commandCode.push_back(code[index]);
                index++;
            }
            expressions->addExpression(new CommandExpression(factory->createCommand(commandCode)));
            index++;
        } else {
            index++;
        }
    }
}
